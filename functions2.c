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

/**
 * nop - The opcode nop doesn’t do anything.
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void nop(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)*head;
	return;
}

/**
 * sub - subtracts the top element of the stack from the second
 * top element of the stack
 * @head: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		global_free(*head);
	}
	(*head)->next->n = (*head)->next->n - (*head)->n;
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
