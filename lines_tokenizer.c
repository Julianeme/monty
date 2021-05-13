#include "monty.h"

char **lines_tokenizer(char *string)
{
	char **cmd_lines = NULL, *input_copy = NULL, *l_counter = NULL;
	int i = 0;

	input_copy = _strdup(string); /*creates a copy of the input string*/
	l_counter = strtok(input_copy, "\n");
	i = 0;
	while (l_counter)/*counts how many lines has the input string = i*/
	{
		i++;
		l_counter = strtok(NULL, "\n");
	}
	free(input_copy);
	i++;
	cmd_lines = malloc(sizeof(char *) * i); /*store com lines in pointers*/
	if(!cmd_lines)
	{
		perror("Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	i = 0;
	cmd_lines[0] = _strdup(strtok(string, "\n"));
	while (cmd_lines[i])
	{
		i++;
		cmd_lines[i] = _strdup(strtok(NULL, "\n"));
	}	/*a ptr to each of the command lines"*/
	cmd_lines[i] = NULL;
	return (cmd_lines); /*returns  **array with each of the command lines*/
}