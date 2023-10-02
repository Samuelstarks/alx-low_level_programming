#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - Reserve memory 1024 bytes for buffer.
* @file: Name of file buffer reserves characters for.
*
* Return: Reference to freshly reserved buffer.
*/
char *create_buffer(char *file)
{
char *buffer;
buffer = malloc(sizeof(char) * 1024);
if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}
return (buffer);
}
/**
* close_file - terminate file descriptors.
* @ms: file descriptor to terminate.
*/
void close_file(int ms)
{
int b;
b = close(ms);
if (b == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close ms %d\n", ms);
exit(100);
}
}
/**
* main - Duplicate contents of file to another file.
* @argc: num of arguments sent to program.
* @argv: array of reference to arguments.
*
* Return: 0 on success.
*
* Description: Exit with code 97 when the argument count is incorrect.
* Exit with code 98 when file_from does not exist or cannot read.
* Exit with code 99 when file_to cannot be created or written.
* Exit with code 100 when file_to or file_from cannot be closed
*/
int main(int argc, char *argv[])
{
int from, to, r, k;
char *buffer;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
do {
if (from == -1 || r == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}
k = write(to, buffer, r);
if (to == -1 || k == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}
r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);
} while (r > 0);
free(buffer);
close_file(from);
close_file(to);
return (0);
}
