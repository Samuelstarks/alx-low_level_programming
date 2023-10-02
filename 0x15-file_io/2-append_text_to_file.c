#include "main.h"
/**
* append_text_to_file - append TXT at end of file.
* @filename: Code will point to name of file.
* @text_content: Code string to add to end of file.
*
* Return: If the func fails or filename is NULL - -1.
*         If file does not exist the user lacks write permissions - -1.
*         Or else - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int o, s, len = 0;
if (filename == NULL)
return (-1);
if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}
o = open(filename, O_WRONLY | O_APPEND);
s = write(o, text_content, len);
if (o == -1 || s == -1)
return (-1);
close(o);
return (1);
}
