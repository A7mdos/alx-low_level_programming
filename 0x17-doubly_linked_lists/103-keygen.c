#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 *
 * @argc: Args count.
 * @argv: Args vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *ex, password[7];
	int idx, temp, str_len = strlen(argv[1]);

	(void)argc;
	ex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (str_len ^ 59) & 63;
	password[0] = ex[temp];

	temp = 0;
	for (idx = 0; idx < str_len; idx++)
		temp += argv[1][idx];
	password[1] = ex[(temp ^ 79) & 63];

	temp = 1;
	for (idx = 0; idx < str_len; idx++)
		temp *= argv[1][idx];
	password[2] = ex[(temp ^ 85) & 63];

	temp = 0;
	for (idx = 0; idx < str_len; idx++)
	{
		if (argv[1][idx] > temp)
			temp = argv[1][idx];
	}
	srand(temp ^ 14);
	password[3] = ex[rand() & 63];

	temp = 0;
	for (idx = 0; idx < str_len; idx++)
		temp += (argv[1][idx] * argv[1][idx]);
	password[4] = ex[(temp ^ 239) & 63];

	for (idx = 0; idx < argv[1][0]; idx++)
		temp = rand();
	password[5] = ex[(temp ^ 229) & 63];
	password[6] = '\0';

	printf("%s", password);
	return (0);
}
