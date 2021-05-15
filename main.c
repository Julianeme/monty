#include "monty.h"

/**
 * main -  an interpreter program for monty byte code
 * @argc: number of arguments passed to the program
 * @argv: arguments passed to the program.
 * Return: 0 on success, error message otherwise
 */

int main(int argc, char **argv)
{
	unsigned int i = 0;
	char **command = NULL, *line_buf = NULL;
	ssize_t bytes = 0;
	size_t line_buf_size = 0;
	stack_t *stack = NULL;
	FILE *fd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bytes = getline(&line_buf, &line_buf_size, fd);
	while (bytes >= 0)
	{
		i++;
		command = words_tokenizer(line_buf);
		if (command[1])
			global.value = value_check(command[1]);
		if (command[0])
		{
			if (strcmp(command[0], "push") == 0 && !command[1])
			{
				fprintf(stderr, "L%u: usage: push integer\n", i);
				free(line_buf);
				exit(EXIT_FAILURE);
			}
			get_op(command[0], &stack, i);
		}
		line_buf = NULL;
		free_grid(command), command = NULL;
		bytes = getline(&line_buf, &line_buf_size, fd);
	}
	free(line_buf);
	free_stack(stack);
	fclose(fd);
	return (0);
}
