# Use a base image with Ubuntu, which is similar to the CI environment
FROM ubuntu:latest

#Default directory
WORKDIR /PasswordStrength

RUN apt-get update && \
    apt-get install -y --no-install-recommends python3 git curl clang llvm lcov default-jdk zip cmake && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN which clang

RUN curl -L https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 -o /usr/local/bin/bazel && \
    chmod +x /usr/local/bin/bazel

RUN which bazel
RUN bazel --version

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/CodeIntelligenceTesting/cifuzz/main/install.sh)"

COPY . /PasswordStrength

WORKDIR /PasswordStrength

RUN ls -a

CMD ["sh", "-c", "cifuzz run test:test --use-sandbox=false > /PasswordStrength/fuzzing.log 2>&1 && cat /PasswordStrength/fuzzing.log && cifuzz finding && cifuzz coverage test"]