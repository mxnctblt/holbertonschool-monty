#include "monty.h"

/**
 * pall - function that print all elements in stack
 * @stack: a pointer on the head of stack
 * @line_number: the number of the line
 * Return: return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void) line_number;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
