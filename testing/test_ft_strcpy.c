

#include "utils.h"

#include "../libasm/libasm.h"

void assert_string_copy(const char *src, char *label) {
    char dest[100];  // Ensure the destination buffer is large enough
    char expected[100];

    char* test = strcpy(expected, src);
    char* test2 = _ft_strcpy(dest, src);

     printf("test: %s\n", test);
        printf("test2: %s\n", test2);

    label = label ? label : "empty string";
    printf("Expected: %s\t", expected);
    printf(" |\t");
    printf("Result: %s\t", dest);
    if(strcmp(expected, dest) == 0) {
        printf_color("green", "OK\n");
    } else {
        fprintf(stderr, "Assertion failed: expected %s, got %s\n", expected, dest);
    }
}

void _ft_strcpy_test() {
    print_header("ft_strcpy");

    // Normal cases
    assert_string_copy("hello world", "hello world");
    assert_string_copy("pouic", "pouic");
    assert_string_copy("pouet", "pouet");

    // Edge cases
    assert_string_copy("a", "single character");
    assert_string_copy("ab", "two characters");
    assert_string_copy("abc", "three characters");
    assert_string_copy("abcdefghijklmnopqrstuvwxyz", "alphabet");
    assert_string_copy("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "uppercase alphabet");
    assert_string_copy("1234567890", "numbers");
    assert_string_copy("!@#$%^&*()", "special characters");
    assert_string_copy(" \t\n\r", "whitespace characters");
    assert_string_copy("long string with multiple words and spaces", "long string");

    // Very long string
    char long_string[51];
    for (int i = 0; i < 50; i++) {
        long_string[i] = 'a';
    }
    long_string[50] = '\0';
    assert_string_copy(long_string, "very long string (1000 'a's)");

    // Null terminator in the middle
    char mid_null_string[] = "hello\0world";
    assert_string_copy(mid_null_string, "null terminator in the middle");

    // Strings with embedded null characters
    char embedded_null_string[] = {'a', 'b', '\0', 'c', 'd', '\0'};
    assert_string_copy(embedded_null_string, "embedded null characters");

    // Unicode characters (assuming UTF-8 encoding)
    assert_string_copy("こんにちは", "Japanese characters");
    assert_string_copy("안녕하세요", "Korean characters");
    assert_string_copy("你好", "Chinese characters");
}

