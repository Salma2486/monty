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
/**
 * pstr -  prints the string starting at the top of the stack
 * @stack: a pointer to linked list
 * @line_number: the line 
 */
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
/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return. 
 */
void rotl(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)line_number;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}
