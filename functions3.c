#include "monty.h"

/**
 * mod - omputes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		global_free(*head);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		global_free(*head);
	}
	(*head)->next->n %= (*head)->n;
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
