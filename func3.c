#include "monty.h"
/**
 * pchar - print the ascii code of the number
 * @stack: linked list pointer 
 * @line_number: line ...
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if(*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 126 || (*stack)->n < 32)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(stack);
                exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
