#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: double list
 * @linenumber: line
 */
void add(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
}
