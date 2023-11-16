#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 */
void pint(stack_t **stack, int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * pop - Remove the top element of the stack.
 * @stack: Pointer to the stack.
 */
void pop(stack_t **stack)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "can't pop an empty stack\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
