#include "monty.h"

int main(int argc, char **argv)
{
	int i = 0;
	char **command = NULL, *line_buf = NULL;
	ssize_t bytes = 0;
	size_t line_buf_size = 0;
	/*stack_t **stack = NULL;*/
	FILE *fd = NULL;

	if (argc > 2)
		exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (!fd)
		exit(EXIT_FAILURE);

	bytes = getline(&line_buf, &line_buf_size, fd);
	while (bytes >= 0)
	{
		i++;
		printf("linea completa del getline: %s\n", line_buf);
		command = words_tokenizer(line_buf);
		value = atoi(command[1]);
		printf("VALUE: %i,  LINEA: %i, COMMAND: %s\n", value, i, command[0]);
		/*get_op(command[0], stack, i);*/
		line_buf = NULL;
		free_grid(command);
		bytes = getline(&line_buf, &line_buf_size, fd);
	}
	free(line_buf);
	return(0);
}
