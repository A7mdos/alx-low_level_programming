#include <stdlib.h>
#include "main.h"

/**
 * print - Prints a string, followed by a new line.
 *
 * @str: The string to be printed.
 */
void print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}


/**
 * rev_string - reverses a string
 *
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int i = 0, length = 0;
	char temp;

	while (s[i++] != '\0')
		length++;

	for (i = 0; i < length / 2; i++)
	{
		temp = s[i];
		s[i] = s[length - 1 - i];
		s[length - 1 - i] = temp;
	}

}



/**
 * _strlen - calculates the length of a string
 *
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0, length = 0;

	while (s[i++] != '\0')
		length++;

	return (length);
}


/**
 * zero_fill - Initialize an array with 0's
 *
 * @arr: The array to be initialized.
 * @size: The size of the array.
 *
 * Return: A pointer to the initialized array.
 */
char *zero_fill(char *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		arr[i] = '0';
		i++;
	}
	return (arr);
}


/**
 * isalldigits - Checks if a string contains only digits.
 * 
 * @str: Given input to check
 *
 * Return: 1 if a number, 0 if otherwise
 */
int isalldigits(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}


/**
 * multiply - Multiply two numbers, given as strings.
 *
 * @num1: The first number, as a string
 * @num2: The second number, as a string
 * @length1: The length of the first string
 * @length2: The length of the second string
 *
 * Return: Pointer to char array
 */
char *multiply(char *num1, char *num2, int length1, int length2)
{
	char *result;
	int i, j, k, product, carry, digit, result_length;

	result_length = length1 + length2 + 1;
	result = malloc(result_length * sizeof(char));
	if (result == NULL)
	{
		print("Error");
		exit(98);
	}

	result = zero_fill(result, result_length);

	i = length2 - 1; carry = k = digit = 0;
	while (i >= 0 && k < (length1 + length2))
	{
		j = length1 - 1;
		k = digit;
		while (j >= 0)
		{
			carry = 0;
			product = (num1[j] - '0') * (num2[i] - '0');
			if (product > 9)
				carry += product / 10;
			product = product % 10;

			if (((result[k] - '0') + product) > 9)
			{
				carry += 1;
				result[k] += (product - 10);
			}
			else
				result[k] += product;

			result[k + 1] += carry;
			k++; j--;
		}
		i--; digit++;
	}

	if (result[k] == '0')
		result[k] = '\0';
	else
		result[k + 1] = '\0';

	return (result);
}


/**
 * remove_zeroes - Remove zeroes from a number, given as a string
 *
 * @str: String to remove zeros from.
 * @len: Length of the string
 *
 * Return: Pointer to new string
 */
char *remove_zeroes(char *str, int len)
{
	int i, j;
	char *nstr;

	i = 0;
	while (str[i] == '0' && str[i] != '\0')
	{
		i++;
	}
	if (len - i == 0)
	{
		nstr = malloc(2 * sizeof(*nstr));
		nstr[0] = '0';
		nstr[1] = '\0';
		return (nstr);
	}
	else
		len -= i;
	nstr = malloc(len * sizeof(*nstr) + 1);
	j = 0;
	while (j < len)
	{
		nstr[j] = str[i];
		j++;
		i++;
	}
	nstr[j] = '\0';
	return (nstr);
}


/**
 * check_zero - Check if the number is zero or if zeros need to be gone.
 *
 * @str: String to check for zeros
 * @len: Length of the string
 *
 * Return: Pointer to new num string
 */
char *check_zero(char *str, int len)
{
	char *num;
	int i;

	if (str[0] == '0' && len != 1)
		num = remove_zeroes(str, len);
	else if (str[0] == '0' && len == 1)
	{
		num = malloc(len + 1);
		if (num == NULL)
		{
			print("Error");
			exit(98);
		}
		num[0] = '0';
		num[1] = '\0';
	}
	else
	{
		num = malloc(len + 1);
		if (num == NULL)
		{
			print("Error");
			exit(98);
		}
		i = 0;
		while (i < len)
		{
			num[i] = str[i];
			i++;
		}
		num[i] = '\0';
	}

	return (num);
}


/**
 * main - Multiplies two positive numbers (passed as strings)
 *		  and prints the result.
 *
 * @argc: The number of arguments supplied to the program
 *		  (the program's name is considered an argument).
 * @argv: An array of pointers to the arguments.
 *
 * Return: On success - 0.
 *		   On failure - 98.
 */
int main(int argc, char *argv[])
{
	int length1, length2;
	char *product, *num1, *num2;

	if (argc != 3)
	{
		print("Error");
		exit(98);
	}

	if (isalldigits(argv[1]) == 0 || isalldigits(argv[2]) == 0)
	{
		print("Error");
		exit(98);
	}

	length1 = _strlen(argv[1]);
	length2 = _strlen(argv[2]);

	num1 = check_zero(argv[1], length1);
	if (*num1 == '0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	num2 = check_zero(argv[2], length2);
	if (*num2 == '0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}

	length1 = _strlen(num1);
	length2 = _strlen(num2);
	if (length1 > length2)
		product = multiply(num1, num2, length1, length2);
	else
		product = multiply(num2, num1, length2, length1);

	rev_string(product);
	print(product);
	free(product);
	free(num1);
	free(num2);

	return (0);
}
