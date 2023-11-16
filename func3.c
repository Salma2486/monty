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
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	
	(void)line_number;
	while(current && current->n != 0)
	{
		if (current->n > 126 || current->n < 32)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
