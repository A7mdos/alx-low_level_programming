#include "main.h"

int _is_divisible(int, int);

/**
 * is_prime_number - Checks if a number is a prime number
 *
 * @n: The number to check if its a prime number.
 *
 * Return: If n is a prime number, 1.
 *		   If n is not a prime number, 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (_is_divisible(n, 2));
}

/**
 * _is_divisible - Checks if number is divisible by any number less than it,
 *				   i.e. is a prime number.
 *
 * @n: The number to check if its a prime number.
 * @divisor: The divisor of @n.
 *
 * Return: If n is a prime number, 1.
 *		   If n is not a prime number, 0.
 */
int _is_divisible(int n, int divisor)
{
	if (divisor >= n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (_is_divisible(n, divisor + 1));
}
