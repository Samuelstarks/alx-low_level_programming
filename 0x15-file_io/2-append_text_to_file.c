#include "main.h"
/**
* append_text_to_file - Append TXT at end of file.
* @filename: Reference to name of file.
* @text_content: Add string to end of file.
*
* Return: If func fails or filename is NULL - -1 or
* If file does not exist, user lacks write permissions - -1.
* Or else - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int z, k, len = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}
z = open(filename, O_WRONLY | O_APPEND);
k = write(z, text_content, len);
if (z == -1 || k == -1)
return (-1);
close(z);
return (1);
}
