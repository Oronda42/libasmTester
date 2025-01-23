#include "utils.h"

#include "../libasm/libasm.h"


void assert_strdup(const char *s, const char *label) {
    char *expected = strdup(s);
    char *result = _ft_strdup(s);

    printf("%s\n", label);
    printf("Expected: %s, Result: %s\n", expected, result);
    if (strcmp(expected, result) == 0) {
        printf_color("green", "OK\n");
    } else {
        printf_color("red", "KO\n");
    }

    free(expected);
    free(result);
}

void assert_strdup_malloc_fail(const char *s, const char *label) {
   
    char *result = _ft_strdup(s);
   
    strerror(errno);

    printf("%s\n", label);
    if (result == NULL) {
        printf_color("green", "OK (malloc failed as expected)\n");
    } else {
        printf_color("red", "KO (malloc did not fail)\n");
        free(result);
    }
}

void _ft_strdup_test() {
    print_header("ft_strdup");

    // Normal cases
    assert_strdup("Hello, World!", "Duplicate 'Hello, World!'");
    assert_strdup("This is a test string.", "Duplicate 'This is a test string.'");

    // Edge cases
    assert_strdup("", "Duplicate empty string");
    assert_strdup("A", "Duplicate single character");

    // Additional Tests
    // Test 1: Duplicate a string with special characters
    assert_strdup("Hello!@#$%^&*()", "Duplicate 'Hello!@#$%^&*()'");

    // Test 2: Duplicate a string with numbers
    assert_strdup("1234567890", "Duplicate '1234567890'");

    // Test 3: Duplicate a string with mixed case
    assert_strdup("HelloWorld", "Duplicate 'HelloWorld'");
    assert_strdup("helloworld", "Duplicate 'helloworld'");

    // Test 4: Duplicate a large string
    char large_str[1001];
    memset(large_str, 'A', 1000);
    large_str[1000] = '\0';
    assert_strdup(large_str, "Duplicate a large string");

    // Test 5: Duplicate a string with null character in the middle
    assert_strdup("Hello\0World", "Duplicate 'Hello\\0World'");
    // test with a malloc who will failed

    // Test 6: Simulate malloc failure
    assert_strdup_malloc_fail("Simulate malloc failure", "Simulate malloc failure");
}
