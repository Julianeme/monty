#include "monty.h"

/**
 *_strdup - duplicates an array
 *@str: array to be copied
 *Return: 0 - NULL if unsuccesuf, otherwise pointer to copied array
 */

char *_strdup(char *str)
{
	int i = 0, a = 0;
	char *array = NULL;

	if (str == 0)
		return (0);
	while (str[a] != '\0')
		a++;
	array = malloc(a * sizeof(char) + 2);
	if (array == 0)
		return (0);
	for (i = 0; i <= a; i++)
	{
		array[i] = str[i];
	}
	array[i] = 00;
	return (array);
}
