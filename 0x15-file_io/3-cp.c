#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *init_buffer(char *file);
void close_file(int fd);

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Usage: cp file_from file_to.
 *				If the number of arguments is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char **argv)
{
	int src_fd, dest_fd, r, w, buffer_size, flags, permissions;
	char *buffer, *src_filename, *dest_filename;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
				"Usage: cp file_from file_to\n");
		exit(97);
	}

	src_filename = argv[1];
	dest_filename = argv[2];

	buffer = init_buffer(dest_filename);

	flags = O_RDONLY;
	src_fd = open(src_filename, flags);

	r = read(src_fd, buffer, buffer_size);

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	permissions = 0664;
	dest_fd = open(dest_filename, flags, permissions);

	do {
		if (src_fd == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n",
					src_filename);
			free(buffer);
			exit(98);
		}

		w = write(dest_fd, buffer, r);
		if (dest_fd == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n",
					dest_filename);
			free(buffer);
			exit(99);
		}

		r = read(src_fd, buffer, buffer_size);

		flags = O_WRONLY | O_APPEND;
		dest_fd = open(dest_filename, flags);

	} while (r);

	free(buffer);
	close_file(src_fd);
	close_file(dest_fd);

	return (0);
}


/**
 * init_buffer - Initializes a buffer of size 1024 bytes
 *				 to store characters from a file.
 *
 * @file: The name of the file for which the buffer is storing characters.
 *
 * Return: On success - A pointer to the newly-allocated buffer.
 *
 * Description: On failure - exit code 99
 */
char *init_buffer(char *file)
{
	char *buffer;
	int buffer_size = 1024;

	buffer = malloc(sizeof(char) * buffer_size);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n",
				file);
		exit(99);
	}

	return (buffer);
}


/**
 * close_file - Closes a file.
 *
 * @fd: The file descriptor of the file to be closed.
 *
 * Description: On failure - exit code 100
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n",
				fd);
		exit(100);
	}
}
