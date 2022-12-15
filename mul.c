#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack
 * @stack: stack
 * @linenumber: line
 */
void mul(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			monty.line_number);
		freeall();
		exit(EXIT_FAILURE);
	}
}
