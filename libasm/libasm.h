#ifndef LIBASM_H
# define LIBASM_H

#include <unistd.h>

extern size_t _ft_strlen(const char *s);
extern char *_ft_strcpy(char *dest, const char *src);
extern int _ft_strcmp(const char *s1, const char *s2);
extern ssize_t _ft_write(int fd, void *buf, size_t count);
extern ssize_t _ft_read(int fd, void *buf, size_t count);
extern char *_ft_strdup(const char *s);

#endif