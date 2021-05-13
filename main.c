#include "monty.h"

/**
 * main - runs and interpretates monty language intructions.
 * @argc: No of arguments in the command line
 * @argv: Arguments in the command line
 * Return: 1 if successfull / Error messagge otherwise
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	int fd, f_size = 0, i = 0, k = 0, num_lett = BUFSIZ;
	char *buff = NULL, **cmd_lines = NULL, **command = NULL;

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
		return (EXIT_FAILURE);
	}
	f_size = read(fd, buff, num_lett); /*f_size stores no. of chars of the file*/
	buff[f_size] = 00;
	cmd_lines = lines_tokenizer(buff); /*split file into lines"*/
	while (cmd_lines[i])
	{
		command = words_tokenizer(cmd_lines[i]);
		char *value = command[2];

		printf("Variable global = %s \n", value);
		/*k = 0;
		while(command[k])
		{
			printf("%s ", command[k]);
			k++;
		}
		printf("\n");
		/*ejecutar el comando leido*/
		i++;
	}
}
