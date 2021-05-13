#include "monty.h"
/**
 * com_storer- spit the command line into words and creates a array of pointers
 * pointing to each one.
 * @string: the string containing the command line to be splitted into words
 * Return: a pointer to the array of pointers cmd_words
 */

char **words_tokenizer(char *string)
{
	char **cmd_words = NULL, *string_cpy = NULL;
	int i = 0;

	string_cpy = _strdup(string);
	cmd_words = malloc(sizeof(char *) * 3);
	i = 0;
	cmd_words[0] = _strdup(strtok(string_cpy, " \t\n"));
	while (cmd_words[i] && i < 2)
	{
		i++;
		cmd_words[i] = _strdup(strtok(NULL, " \t\n"));
	}
	cmd_words[i] = NULL;
	free(string_cpy);
	return (cmd_words);
}