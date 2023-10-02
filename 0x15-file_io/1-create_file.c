#include "main.h"

/**
* create_file - Create the file.
* @filename: Reference to name of file to create.
* @text_content: A reference to string to write to file.
*
* Return: If the function fails - -1.
*         Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
int ms, k, len = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}
ms = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
k = write(ms, text_content, len);
if (ms == -1 || k == -1)
return (-1);
close(ms);
return (1);
}
