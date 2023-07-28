#include "main.h"

char *add_numbers(char *n1, char *n2, char *r, int r_index);

/**
 * infinite_add - Adds two numbers.
 *
 * @n1: A pointer to the first number to be added.
 * @n2: A pointer to the second number to be added.
 * @r: The buffer used to store the result.
 * @size_r: The buffer size.
 *
 * Return: If result can be stored in r, a pointer to the result.
 *         If result can't be stored in r, 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, r_index, n1_length = 0, n2_length = 0;

	i = 0;
	while (n1[i++] != '\0')
		n1_length++;

	i = 0;
	while (n2[i++] != '\0')
		n2_length++;

	if (n1_length + 1 >= size_r || n2_length + 1 >= size_r)
		return (0);

	n1 += n1_length - 1;
	n2 += n2_length - 1;
	r[size_r] = '\0';

	r_index = --size_r;
	return (add_numbers(n1, n2, r, r_index));
}


/**
 * add_numbers - Adds the numbers stored in two strings.
 *
 * @n1: A pointer to the right of the first number
 * @n2: A pointer to the right of the second number
 * @r: The buffer used to store the result.
 * @r_index: The current index of the buffer.
 *
 * Return: If r can store the sum - a pointer to the result.
 *         If r cannot store the sum - 0.
 */
char *add_numbers(char *n1, char *n2, char *r, int r_index)
{
	int num, carry = 0;

	while (*n1 != '\0' && *n2 != '\0')
	{
		num = (*n1 - '0') + (*n2 - '0') + carry;
		r[r_index] = '0' + (num % 10);
		carry = num / 10;

		n1--;
		n2--;
		r_index--;
	}

	while (*n1 != '\0')
	{
		num = (*n1 - '0') + carry;
		r[r_index] = '0' + (num % 10);
		carry = num / 10;

		n1--;
		r_index--;
	}

	while (*n2 != '\0')
	{
		num = (*n2 - '0') + carry;
		r[r_index] = '0' + (num % 10);
		carry = num / 10;

		n2--;
		r_index--;
	}

	if (carry && r_index >= 0)
	{
		r[r_index] = '0' + carry;
		return (r + r_index);
	}
	else if (carry && r_index < 0)
	{
		return (0);
	}
	else
	{
		return (r + r_index + 1);
	}
}
