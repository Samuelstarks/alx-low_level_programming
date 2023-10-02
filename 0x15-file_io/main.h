#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
* Read a specified num of chars from a text file.
*
* @param filename The name of the file to read.
* @param letters The maximum num of chars to read.
* @return The num of chars read or -1 on error.
*/
ssize_t read_text_from_file(const char *filename, size_t max_characters);
/**
 * Create a new file with the given filename and write the provided text content to it.
 *
 * @param filename The name of the file to create.
 * @param text_content The content to write to the file.
 * @return 1 on success or -1 on error.
 */
int create_file_with_content(const char *filename, const char *text_content);

/**
* Append text content to an existing file specified by the filename.
*
* @param filename The name of the file to which to append.
* @param text_content The content to append to the file.
* @return 1 on success or -1 on error.
*/
int append_text_to_existing_file(const char *filename, const char *text_content);
#endif /* FILE_OPERATIONS_H */
