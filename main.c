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
	ssize_t bytes = 0;
	size_t line_buf_size = 0;
	stack_t *stack = NULL;

	global.line_buf = NULL, global.command = NULL;

	argc_checker(argc);
	global.fd = fopen(argv[1], "r");
	if (!global.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bytes = getline(&global.line_buf, &line_buf_size, global.fd);
	while (bytes >= 0)
	{
		i++;
		if (!batman(global.line_buf))
		{
			bytes = getline(&global.line_buf, &line_buf_size, global.fd);
			continue;
		}
		global.command = words_tokenizer(global.line_buf);
		if (global.command[1] && strcmp(global.command[0], "push") == 0)
			global.value = value_check(stack, global.command[1], i);
		if (global.command[0])
		{
			if (strcmp(global.command[0], "push") == 0 && !global.command[1])
				push_error(stack, i);
			get_op(global.command[0], &stack, i);
		}
		free_grid(global.command), global.command = NULL;
		free(global.line_buf);
		global.line_buf = NULL;
		bytes = getline(&global.line_buf, &line_buf_size, global.fd);
	}
	camilo_patino(stack);
	return (0);
}
