#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

size_t my_strlen(char *str);
char *my_strchr(char *str, char c);
int my_strcmp (const char *str1, const char *str2 );
int my_strncmp (const char *str1, const char *str2 , size_t len);
int my_strcasecmp(const char *str, const char *str2);

void *my_memset(void *str, int c, size_t n);
void *my_memcpy ( void *dest, const void *src, size_t len );
void *my_memmove ( void *dest, const void *src, size_t len );
char *my_index(const char *str, int c);

ssize_t my_read(int fd, void *buffer, size_t len);
ssize_t my_write(int fd, const void *buffer, size_t len);
