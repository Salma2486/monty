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
/**
 * div_op - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_number: the number of line
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top->next->n /= top->n;
	*stack = top->next;
	top->next->prev = NULL;
	free(top);
}
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the stack
 * @line_number: the number of line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(top);
}
