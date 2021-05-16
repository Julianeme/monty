#include "monty.h"

/**
 * add - adds two top elements of the stack and deletes the top one
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		global_free(*head);
	}
	(*head)->next->n += (*head)->n;
	if (temp->next)
	{
		*head = temp->next;
		temp->next->prev = NULL;
	}
	else
	{
		*head = NULL;
	}
	free(temp);
}