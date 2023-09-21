# Use a base image with Ubuntu, which is similar to the CI environment
FROM ubuntu:latest

#Default directory
WORKDIR /PasswordStrength



RUN apt-get update && \
    apt-get install -y --no-install-recommends python3 git curl clang llvm lcov default-jdk zip && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN which clang
RUN apt-get update && apt-get install -y cmake

RUN cmake --version

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/CodeIntelligenceTesting/cifuzz/main/install.sh)"

# Copying local directories and files instead of cloning from a repo
RUN mkdir PasswordStrength
COPY . /PasswordStrength

WORKDIR /PasswordStrength
RUN ls -a

CMD ["sh", "-c", "cifuzz run test:test1 --use-sandbox=false > /PasswordStrength/fuzzing.log 2>&1 && cat /PasswordStrength/fuzzing.log && cifuzz finding && cifuzz coverage test"]