#include "monty.h"
void execute_instructions(FILE *file);
/**
 * check_for_int - check for int
 * @in: an array
 * Return: val or -1
 */
int check_for_int(char in[127])
{
	int val, i = 0;

	while (in[i] != '\0')
	{
		if (in[i] == '.' || ((in[i] > 57 || in[i] < 48) && in[i] != '-'))
		{
			return (-1);
		}
		i++;
	}
	val = atoi(in);
	return (val);
}
/**
 * push - push element to the stacks
 * @line_number: kjbdkhsjd
 * @stack: stack
 * @value: the element we want to push
 * Return: its void
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;
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
 * @line_number: oihnfeqoiw
 * @stack: the stack
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
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
	char value[127];
	int num;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (sscanf(line, "%s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (sscanf(line, "%*s %s", value) == 1 && check_for_int(value) != -1)
				{
					num = check_for_int(value);
					if (num != -1)
						push(&head, num, line_number);
				}
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
				pall(&head, line_number);
			else if (strcmp(opcode, "pint") == 0)
				pint(&head, line_number);
			else if (strcmp(opcode, "pop") == 0)
				pop(&head, line_number);
			else if (strcmp(opcode, "swap") == 0)
				swap(&head, line_number);
			else if (strcmp(opcode, "add") == 0)
				add(&head, line_number);
			else if (strcmp(opcode, "nop") == 0)
				nop(&head, line_number);
			else if (strcmp(opcode, "sub") == 0)
				sub(&head, line_number);
			else if (strcmp(opcode, "div") == 0)
				div_op(&head, line_number);
			else if (strcmp(opcode, "mul") == 0)
				mul(&head, line_number);
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
