#include "utils.h"

#include "../libasm/libasm.h"

void assert_strcmp(const char *s1, const char *s2, const char *label) {
    int expected = strcmp(s1, s2);
    int result = _ft_strcmp(s1, s2);

    printf("%s\n", label);
    printf("Expected: %d, Result: %d\n", expected, result);
    if((expected == 0 && result == 0) || (expected < 0 && result < 0) || (expected > 0 && result > 0)) {
        printf_color("green", "OK\n");
    } else {
        printf_color("red", "KO\n");
    }
}

void _ft_strcmp_test() {

    print_header("ft_strcmp");

    // Normal cases
    assert_strcmp("Hello", "Hello", "Compare 'Hello' with 'Hello'");
    assert_strcmp("Hello", "World", "Compare 'Hello' with 'World'");
    assert_strcmp("abc", "abcd", "Compare 'abc' with 'abcd'");
    assert_strcmp("abcd", "abc", "Compare 'abcd' with 'abc'");

    // Edge cases
    assert_strcmp("", "", "Compare empty strings");
    assert_strcmp("A", "A", "Compare single characters");
    assert_strcmp("A", "B", "Compare different single characters");
    assert_strcmp("A", "", "Compare single character with empty string");
    assert_strcmp("", "A", "Compare empty string with single character");

    // Special cases
    assert_strcmp("Hello\0World", "Hello\0World", "Compare 'Hello\\0World' with 'Hello\\0World'");
    
    // Additional Tests
    // Test 1: Compare strings with different lengths
    assert_strcmp("short", "longerstring", "Compare 'short' with 'longerstring'");
    assert_strcmp("longerstring", "short", "Compare 'longerstring' with 'short'");

    // Test 2: Compare strings with special characters
    assert_strcmp("Hello!", "Hello?", "Compare 'Hello!' with 'Hello?'");
    assert_strcmp("Hello@", "Hello#", "Compare 'Hello@' with 'Hello#'");

    // Test 3: Compare strings with numbers
    assert_strcmp("123", "123", "Compare '123' with '123'");
    assert_strcmp("123", "124", "Compare '123' with '124'");
    assert_strcmp("124", "123", "Compare '124' with '123'");

    // Test 4: Compare strings with mixed case
    assert_strcmp("hello", "Hello", "Compare 'hello' with 'Hello'");
    assert_strcmp("Hello", "hello", "Compare 'Hello' with 'hello'");

    // Complex cases
    // Test 5: Compare with NULL inputs
    // assert_strcmp(NULL, "Hello", "Compare NULL with 'Hello'");
    // assert_strcmp("Hello", NULL, "Compare 'Hello' with NULL");
    // assert_strcmp(NULL, NULL, "Compare NULL with NULL");
}