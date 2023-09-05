#include "main.h"

/**
 * create_file - Creates a file.
 *
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, flags, w, len = 0;
	mode_t permissions;

	if (filename == NULL)
		return (-1);

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	permissions = S_IRUSR | S_IWUSR;

	fd = open(filename, flags, permissions);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
	}

	w = write(fd, text_content, len);
	if (w == -1)
		return (-1);

	close(fd);

	return (1);
}
