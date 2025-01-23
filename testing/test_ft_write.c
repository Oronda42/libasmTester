#include "utils.h"

#include "../libasm/libasm.h"

void assert_write(int fd, char *str, ssize_t expected, const char *label) {
    ssize_t ret = _ft_write(fd, str, expected);
   if(ret == -1) {
        perror("_ft_write:");
         ssize_t ret2 = write(fd, str, expected);
         if(ret2 == -1) {
            perror("write:");
         }
            
    }
    printf("%s\n", label);
    printf("Expected: %zd, Result: %zd\n", expected, ret);
    if (ret == expected) {
        printf_color("green", "OK\n");
    } else {
        printf_color("red", "KO\n");
    }
}

void _ft_write_test() {
    print_header("ft_write");

    // Test 1: Write to stdout
    assert_write(1, "Hello, World!\n", 14, "Write to stdout");

    // Test 2: Write to a file
    int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert(fd != -1);
    assert_write(fd, "Hello, File!\n", 13, "Write to a file");
    close(fd);

    // Test 3: Write with invalid file descriptor
    assert_write(-1, "Invalid FD\n", -1, "Write with invalid file descriptor");

    // Additional Tests
    // Test 4: Write an empty string
    assert_write(1, "", 0, "Write an empty string");

    // Test 5: Write a large string
    char large_str[1001];
    memset(large_str, 'A', 1000);
    large_str[1000] = '\0';
    assert_write(1, large_str, 1000, "Write a large string");

    // Test 6: Write to a read-only file
    fd = open("test_file.txt", O_RDONLY);
    assert(fd != -1);
    assert_write(fd, "Read-only test\n", -1, "Write to a read-only file");
    close(fd);

    // Test 7: Write to a closed file descriptor
    fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    assert(fd != -1);
    close(fd);
    assert_write(fd, "Closed FD test\n", -1, "Write to a closed file descriptor");
}

