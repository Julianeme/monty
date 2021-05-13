#include "monty.h"

/**
 * free_cmd -  frees a 2 dimensional array
 * @array: is a doble pointer
 */

void double_ptr_free(char **array)
{
	int x = 0;

	for (x = 0; array[x] != NULL; x++)
		free(array[x]);
	free(*array);
}

/**
 * free_dlistint -  frees the memory allocated for a doubly linked list
 * @stack: a pointer to start of the element of the list
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	while (stack)
	{
		temp = (*stack)->next;
		free(stack);
		*stack = temp;
	}
	free(*stack);
}