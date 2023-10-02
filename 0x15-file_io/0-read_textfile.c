#include "main.h"
#include <stdlib.h>

/**
* read_textfile- Read and print TXT file to STDOUT.
* @filename: Reading the TXT file
* @letters: num of letters to read
* Return: s- actual number of bytes read and printed
* and 0 when function fails or NULL if filename fails.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t ab;
ssize_t s;
ssize_t t;
ab = open(filename, O_RDONLY);
if (ab == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(ab, buf, letters);
s = write(STDOUT_FILENO, buf, t);
free(buf);
close(ab);
return (s);
