#include <assert.h>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

#include "../src/passchecker.h"

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size) {

  FuzzedDataProvider fuzzed_data(data, size);
  std::string my_string = fuzzed_data.ConsumeRandomLengthString();

  string result = passchecker(my_string);
}
