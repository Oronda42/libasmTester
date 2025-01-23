#include "utils.h"

#include "../libasm/libasm.h"

void assert_string_length(char *str, char *label)
{
    size_t expected = strlen(str);
    size_t result = _ft_strlen(str);
    printf("%s\n\t", label);
    printf("%lu\t", expected);
    printf(" |\t");
    printf("%lu\t", result);
    if (expected != result)
    {
        fprintf(stderr, "Assertion failed: expected %lu, got %lu\n", expected, result);
    }
    else
    {
        printf_color("green", "OK\n");
    }
}

void _ft_strlen_test()
{
    print_header("ft_strlen");

    // Normal cases
    assert_string_length("hello world", "hello world");
    assert_string_length("pouic", "pouic");
    assert_string_length("pouet", "pouet");

    // Edge cases
    assert_string_length("a", "single character");
    assert_string_length("ab", "two characters");
    assert_string_length("abc", "three characters");
    assert_string_length("abcdefghijklmnopqrstuvwxyz", "alphabet");
    assert_string_length("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "uppercase alphabet");
    assert_string_length("1234567890", "numbers");
    assert_string_length("!@#$%^&*()", "special characters");
    assert_string_length(" \t\n\r", "whitespace characters");
    assert_string_length("long string with multiple words and spaces", "long string");

    // Very long string
    char long_string[1001];
    for (int i = 0; i < 1000; i++)
    {
        long_string[i] = 'a';
    }
    long_string[1000] = '\0';
    assert_string_length(long_string, "very long string (1000 'a's)");

    // Null terminator in the middle
    char mid_null_string[] = "hello\0world";
    assert_string_length(mid_null_string, "null terminator in the middle");

    // Strings with embedded null characters
    char embedded_null_string[] = {'a', 'b', '\0', 'c', 'd', '\0'};
    assert_string_length(embedded_null_string, "embedded null characters");

    // Unicode characters (assuming UTF-8 encoding)
    assert_string_length("こんにちは", "Japanese characters");
    assert_string_length("안녕하세요", "Korean characters");
    assert_string_length("你好", "Chinese characters");
}