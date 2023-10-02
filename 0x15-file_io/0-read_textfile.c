#include "main.h"
#include <stdlib.h>

/**
* read_textfile- Read, Print TXT file to STANDARD OUTPUT.
* @filename: Reading TXT file
* @letters: num of letters to read
* Return: k- read and print actual num of bytes or
* 0 when func fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd;
ssize_t k;
ssize_t t;
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
k = write(STDOUT_FILENO, buf, t);
free(buf);
close(fd);
return (k);
}
