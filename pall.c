#include "monty.h"

/**
 * pall - print all members
 * @stack: double list
 * @linenumber: line
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *h = *stack;

	if (!*stack)
	{
		return;
	}
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
