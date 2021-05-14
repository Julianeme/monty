#include "monty.h"
/**
 * words_tokenizer- splits the string line into words and
 * creates a array of pointers
 * pointing to each one.
 * @string: the string containing the string line to be splitted into words
 * Return: a pointer to the array of pointers cmd_words
 */

char **words_tokenizer(char *string)
{
	int position = 0;
	char *token = NULL;
	char **tokens = NULL;

	/*allocate memory to pointer tokens*/
	tokens = malloc((count_words(string) + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	/* pointer receiving tokenized string*/
	token = strtok(string, " \t\r\n");
	/*as long as tokens is different from null it makes a copy of token in token*/
	while (token != NULL && position < 2)
	{
		tokens[position] = _strdup(token);
		/*end in null*/
		token = strtok(NULL, " \t\r\n");
		position++;
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * count_words - function that counts words
 * @string: sentence containing the words to count
 * Return: number of words
 */
int count_words(char *string)
{
	int cont1, cont2 = 0;

	for (cont1 = 0; string[cont1]; cont1++)
	{
		if (string[cont1] == 32 && string[cont1 + 1] != 32 && string[cont1 + 1] != 0)
			cont2++;
	}
	if (string[0] != 32)
		cont2++;
	return (cont2);
}
