#include "dog.h"
#include <stdlib.h>

unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);


/**
 * new_dog - Creates a new dog.
 * @name: The name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 *
 * Return: The new struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dogptr;

	dogptr = malloc(sizeof(dog_t));
	if (dogptr == NULL)
		return (NULL);

	dogptr->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (dogptr->name == NULL)
	{
		free(dogptr);
		return (NULL);
	}

	dogptr->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (dogptr->name == NULL)
	{
		free(dogptr->name);
		free(dogptr);
		return (NULL);
	}

	_strcpy(dogptr->name, name);
	dogptr->age = age;
	_strcpy(dogptr->owner, owner);

	return (dogptr);
}


/**
 * _strlen - Calculates the length of a string
 *
 * @s: The string to get the length of
 *
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0, length = 0;

	while (s && s[i++])
		length++;

	return (length);
}


/**
 * _strcpy - Copies the string pointed to by src, including the terminating
 *			 null byte (\0), to the buffer pointed to by dest
 *
 * @src: A pointer to the source string.
 * @dest: A pointer to the destination string.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src && src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}
