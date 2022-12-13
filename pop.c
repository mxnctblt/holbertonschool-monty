#include "monty.h"

/**
 * pop - removes a node from the top of list
 * @stack: double list
 * @linenumber: line
 */
void pop(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *freeable = *stack;

	if (*stack)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(freeable);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n"
			, monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
}
