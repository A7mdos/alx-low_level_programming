#include "main.h"

int _strlen_recursion(char *s);
int _is_palindrome(char *s, int head, int tail);

/**
 * is_palindrome - Checks if a string is a palindrome.
 *
 * @s: The string to be checked.
 *
 * Return: If the string is a palindrome, 1.
 *         If the string is not a palindrome, 0.
 */
int is_palindrome(char *s)
{
	int length, head, tail;

	length = _strlen_recursion(s);
	head = 0;
	tail = length - 1;

	if (tail <= head)
		return (1);

	return (s[head] == s[tail] && _is_palindrome(s, head + 1, tail - 1));
}


/**
 * _strlen_recursion - Returns the length of a string.
 *
 * @s: The string to measure the length of.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}


/**
 * _is_palindrome - Checks if the part between 2 indices
 *					of a string is a palindrome.
 *
 * @s: A pointer to the beginning of the string to be checked.
 * @head: The first (head) index.
 * @tail: The last (tail) index.
 *
 * Return: If the string between @head and @tail is a palindrome, 1.
 *         If the string between @head and @tail is not a palindrome, 0.
 */
int _is_palindrome(char *s, int head, int tail)
{
	if (tail <= head)
		return (1);

	return (s[head] == s[tail] && _is_palindrome(s, head + 1, tail - 1));
}
