#include "monty.h"
void execute_instructions(FILE *file);
/**
 * push - push element to the stacks
 * @stack: stack
 * @value: the element we want to push
 * Return: its void
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
	head = *stack;
}
/**
 * pall - print all the element in stacks
 * @stack: the stack
 * Return: void
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 *execute_instructions - read the line by line
 *@file: pointer to access file
 *Return: void
 */
void execute_instructions(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char opcode[256];
	int value;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (sscanf(line, "%s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (sscanf(line, "%*s %d", &value) == 1)
					push(&head, value);
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					fclose(file);
					free_stack(&head);
					free(line);
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(opcode, "pall") == 0)
				pall(&head);
			else if (strcmp(opcode, "pint") == 0)
				pint(&head);
			else if (strcmp(opcode, "pop") == 0)
				pop(&head);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(file);
				free_stack(&head);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
}
/**
 *free_stack - This is the entry point of the code
 *@stack: drdgfs
 *Return:0 Success
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
	*stack = NULL;
}

