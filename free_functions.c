#include "monty.h"

/**
 * free_grid -  frees a 2 dimensional array
 * @grid: is a doble pointer
 */

void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

/**
 * free_stack -  frees the memory allocated for a doubly linked list
 * @stack: a pointer to start of the element of the list
 */

void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
/**
 * global_free - free memory of the global structure
 * @stack: double linked list stack
 * Return: void
 */

void global_free(stack_t *stack)
{
	free(global.line_buf);
	free_stack(stack);
	fclose(global.fd);
	free_grid(global.command);
	exit(EXIT_FAILURE);
}
/**
 * camilo_patino - free memory of the main (in honor to camilo patiño)
 * @stack: double linked list stack
 */
void camilo_patino(stack_t *stack)
{
	free(global.line_buf);
	free_stack(stack);
	fclose(global.fd);
	free(global.command);
}
