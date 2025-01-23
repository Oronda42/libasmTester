#include "utils.h"

#include "../libasm/libasm.h"

void create_test_file() {
    int fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        strerror(errno);
        return;
    }
    write(fd, "This is a test file with some content to read.", 46);
    close(fd);
}

void assert_read(int fd, size_t count, const char *label) {
    char buf1[100] = {0};
    char buf2[100] = {0};

    lseek(fd, 0, SEEK_SET);  // Reset file descriptor position
    ssize_t ret2 = _ft_read(fd, buf2, count);
    if(ret2 == -1) {
        perror("_ft_read");
        
    }
    lseek(fd, 0, SEEK_SET);
    ssize_t ret1 = read(fd, buf1, count);
    if(ret1 == -1) {
        perror("read");
       
    }

    printf("%s\n", label);
    printf("Expected: %zd, Result: %zd\n", ret1, ret2);
    if (ret1 == ret2) {
        printf_color("green", "OK\n");
    } else {
        printf_color("red", "KO\n");
    }

    
}

void _ft_read_test() {
    print_header("ft_read");

    create_test_file();

    int fd = open("test_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }

    // Normal cases
    assert_read(fd, 20, "Read 20 bytes");
    assert_read(fd, 10, "Read 10 bytes");

    // Edge cases
    assert_read(fd, 0, "Read 0 bytes");
    assert_read(fd, 100, "Read 100 bytes");

    // Additional Tests
    // Test 1: Read from an empty file
    int empty_fd = open("empty_file.txt", O_RDONLY | O_CREAT | O_TRUNC, 0644);
    assert(empty_fd != -1);
    assert_read(empty_fd, 10, "Read from an empty file");
    close(empty_fd);

    // Test 2: Read with invalid file descriptor
    assert_read(-1, 10, "Read with invalid file descriptor");
    perror("open");
   

    // Test 3: Read from a closed file descriptor
    close(fd);
    assert_read(fd, 10, "Read from a closed file descriptor");
    perror("open");
    

    // Test 4: Read a large amount of data
    fd = open("test_file.txt", O_RDONLY);
    assert(fd != -1);
    assert_read(fd, 1000, "Read a large amount of data");

    
    close(fd);
}

