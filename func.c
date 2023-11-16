#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: the number of line
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
 * @line_number: the number of line
 */
void pop(stack_t **stack, int line_number)
{
	stack_t *top = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(top);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the number of line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	if (temp->next)
		temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;
}
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the number of line
 */
void add(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
                free_stack(stack);
                exit(EXIT_FAILURE);
        }

        (*stack)->next->n += (*stack)->n;
        pop(stack, line_number);
}
