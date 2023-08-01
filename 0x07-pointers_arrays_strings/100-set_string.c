#include "main.h"

/**
 * set_string - Sets the value of a pointer to a character.
 *
 * @s: The pointer to set the value of.
 * @to: The character.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
