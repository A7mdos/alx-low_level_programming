#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * isalldigits - Check if a string contains a non-digit char
 * @str: The string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int isalldigits(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}


/**
 * _strlen - Calculate the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}


/**
 * error_and_exit - Handle error_and_exit for main
 */
void error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - Multiply two string digits and the save the result in the destination
 * @s1: The first string that contains only digits
 * @s2: The second string that contains only digits
 * @len1: The length of the first string
 * @len2: The length of the second string
 * @result: The destination to save the results
 *
 * Return: void
 */
void multiply(char *s1, char *s2, int len1, int len2, int *result)
{
	int i, digit1, digit2, carry;

	for (i = 0; i <= len1 + len2; i++)
		result[i] = 0;

	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		digit1 = s1[len1] - '0';
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			digit2 = s2[len2] - '0';
			carry += result[len1 + len2 + 1] + (digit1 * digit2);
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
}

/**
 * print_result - print the result of the multiplication
 * @result: The result to be printed
 * @len: The length of the memory allocated for result
 *
 * Return: void
 */
void print_result(int *result, int len)
{
	int i, a = 0;

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			putchar(result[i] + '0');
	}
	if (!a)
		putchar('0');
	putchar('\n');
}


/**
 * main - Multiply two positive numbers and print the result
 *	  num1 and num2 should only be composed of digits. If not,
 *	  or if the number of arguments is incorrect:
 *	  print "Error", followed by a new line,
 *	  and exit with a status of 98
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: If the multiplication is Successful - 0
 *	   If malloc fails - 1
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, *result;

	s1 = argv[1], s2 = argv[2];

	if (argc != 3 || !isalldigits(s1) || !isalldigits(s2))
		error_and_exit();

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;

	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);

	multiply(s1, s2, len1, len2, result);
	print_result(result, len);

	free(result);

	return (0);
}
