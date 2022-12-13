#include "monty.h"

/**
 * swap - swap place of top two members in stack
 * @stack: double list
 * @linenumber: line
 */
void swap(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	int sw;

	if (*stack && (*stack)->next)
	{
		sw = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = sw;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
				monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
}
