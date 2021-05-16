#include "monty.h"
/**
 * push_error -  xxx
 * @i: xxxx
 * Return: void
 */

void push_error(stack_t *stack_s, unsigned int i)
{
	fprintf(stderr, "L%u: usage: push integer\n", i);
	global_free(stack_s);
}
