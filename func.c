#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 */
void pint(stack_t **stack)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "can't pint, stack empty\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
