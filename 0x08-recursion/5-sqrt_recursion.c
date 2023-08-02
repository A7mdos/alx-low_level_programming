#include "main.h"

int square_root_recursion(int n, int root);

/**
 * _sqrt_recursion - Returns the natural square root of a number
 *
 * @n: The number to find the square root of.
 *
 * Return: If n has a natural square root, square root of n.
 *		   If n does not have a natural square root, -1
 */
int _sqrt_recursion(int n)
{
	return (square_root_recursion(n, 0));
}

/**
 * square_root_recursion - Finds square root of number
 *
 * @n: The number to find the square root of.
 * @root: The root to test.
 *
 * Return: If n has a natural square root, square root of n.
 *		   If n does not have a natural square root, -1
 */
int square_root_recursion(int n, int root)
{
	if (root * root > n)
		return (-1);
	if (root * root == n)
		return (root);
	return (square_root_recursion(n, root + 1));
}
