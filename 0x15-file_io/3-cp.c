#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffer(char *file);
void close_file(int fd);
/**
* create_buffer - Reserve 1024 bytes for the  buffer.
* @file: file buffer is used to store characters for named file.
*
* Return: A reference to the freshly allocated buffer.
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
* @ab: file descriptor to terminate.
*/
void close_file(int ab)
{
int x;
x = close(ab);
if (x == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ab);
exit(100);
}
}
/**
* main - Duplicate contents of one file into another file.
* @argc: The count of arguments provided to the program.
* @argv: An array of reference to the arguments.
*
* Return: 0 on success.
*
* Description: In case of incorrect argument count, exit with a code of 97.
* If file_from becomes non-existent or unreadable, exit code 98.
* If it is not possible to create or write to file_to, use exit code 99.
* If file_to or file_from cannot be terminated, exit code 100.
*/
int main(int argc, char *argv[])
{
int from, to, r, s;
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

s = write(to, buffer, r);
if (to == -1 || s == -1)
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

