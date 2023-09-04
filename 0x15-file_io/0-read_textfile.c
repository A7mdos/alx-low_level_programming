#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standard output.
 *
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         Otherwise - the actual number of letters the
 *					   function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t read_chars_count, printed_chars_count;
	void *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	read_chars_count = read(fd, buffer, letters);
	if (read_chars_count == -1)
		return (0);

	printed_chars_count = write(STDOUT_FILENO, buffer, read_chars_count);

	return (printed_chars_count);
}
