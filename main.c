#include "monty.h"

/**
 * main - runs and interpretates monty language intructions.
 * @argc: No of arguments in the command line
 * @argv: Arguments in the command line
 * Return: 1 if successfull / Error messagge otherwise
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	int fd, f_size = 0, num_lett = BUFSIZ;
	char *buff = NULL, **cmd_lines = NULL, **command = NULL;
	unsigned int i = 0;
	stack_t **stack = NULL;

	buff = malloc(num_lett * sizeof(char));
	if (!buff)
	{
		perror("Error: malloc failed");
		return (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Can't open file");
		free(buff);
		return (EXIT_FAILURE);
	}
	f_size = read(fd, buff, num_lett); /*f_size stores no. of chars of the file*/
	/*ADD ERROR MESSAGGE IF CANT READ*/
	if (f_size == -1)
	{
		close(fd);
		free(buff);
		return (0);
	}
	buff[f_size] = 00;
	cmd_lines = lines_tokenizer(buff); /*split file into lines"*/
	while (cmd_lines[i])
	{
		command = words_tokenizer(cmd_lines[i]);
		unsigned int value = atoi(command[1]);
		/*INSERTAR llamado a function pointers en esta linea*/
		get_op(command[0], stack, i);
		double_ptr_free(command);
		*command = NULL;

		printf("Variable global = %i \n", value);
		/*k = 0;
		while(command[k])
		{
			printf("%s ", command[k]);
			k++;
		}
		printf("\n");
		ejecutar el comando leido*/
		i++;
	}
double_ptr_free(cmd_lines);
free_stack(stack);
}
