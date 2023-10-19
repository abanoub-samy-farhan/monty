#include "monty.h"

void add_to_stack(stack_t **new_node, unsigned int line)
{
	stack_t *tmp;

	(void)(line);
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

void print_top(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	printf("%d\n", (*stack)->n);
}
