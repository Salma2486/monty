#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @line_number: the number of line
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	top->next->n -= top->n;
	*stack = top->next;
	top->next->prev = NULL;
	free(top);
}
