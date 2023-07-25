#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 *
 * Return: 0
 */
int main(void)
{
	char passwd[84];
	int i = 0, sum = 0, difference, difference_half1, difference_half2;

	srand(time(0));

	while (sum < 2772)
	{
		passwd[i] = rand() % 94 + 33;
		sum += passwd[i];
		i++;
	}

	passwd[i] = '\0';

	if (sum != 2772)
	{
		difference = (sum - 2772);
		difference_half1 = difference / 2;
		difference_half2 = difference / 2;

		if (difference % 2 != 0)
			difference_half1++;

		i = -1;
		while (passwd[++i])
		{
			if (passwd[i] >= (difference_half1 + 33))
			{
				passwd[i] -= difference_half1;
				break;
			}
		}

		i = -1;
		while (passwd[++i])
		{
			if (passwd[i] >= (difference_half2 + 33))
			{
				passwd[i] -= difference_half2;
				break;
			}
		}
	}

	printf("%s", passwd);

	return (0);
}
