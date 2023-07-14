#include <unistd.h>


/**
 * main - Prints a string to standard error.
 *
 * Return: 1
 */

int main(void)
{
	char message[59] = "and that piece of art is useful\" - \
Dora Korpar, 2015-10-19\n";

	write(2, message, 59);

	return (1);
}
