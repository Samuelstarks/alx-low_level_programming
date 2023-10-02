#include "main.h"
#include <stdlib.h>
/**
* read_textfile- Read and print text file to STDOUT.
* @filename: read the text file
* @letters: num of letters to read
* Return: S if actual number of bytes read and printed
*         0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd;
ssize_t s;
ssize_t t;
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
s = write(STDOUT_FILENO, buf, t);
free(buf);
close(fd);
return (s);
