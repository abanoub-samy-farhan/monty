#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

void add_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp;
	if (!(*stack) || stack == NULL)
	{
		error_handle_2(1, line, "add");
	}

	tmp = *stack;
	if (tmp->next != NULL)
	{
		tmp->next->n = tmp->next->n + tmp->n;
		(*stack) = tmp->next;
		free(tmp);
	}
	else
		error_handle_2(1, line, "add");
}

void sub_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!(*stack) || stack == NULL)
	{
		error_handle_2(1, line, "sub");
	}

	tmp = *stack;
	if (tmp->next != NULL)
	{
		tmp->next->n = tmp->next->n - tmp->n;
		(*stack) = tmp->next;
		free(tmp);
	}
	else
		error_handle_2(1, line, "sub");
}

void div_stack(stack_t **stack, unsigned int line)
{
        stack_t *tmp;
	if (!(*stack) || stack == NULL)
	{
                error_handle_2(1, line, "div");
        }

        tmp = *stack;
        if (tmp->next != NULL && tmp->n != 0)
        {
                tmp->next->n = tmp->next->n / tmp->n;
                (*stack) = tmp->next;
                free(tmp);
        }
        else
                tmp->n == 0 ? error_handle_2(2, line) : error_handle_2(1, line, "div");
}

void mul_stack(stack_t **stack, unsigned int line)
{
        stack_t *tmp;
        if (!(*stack) || stack == NULL)
        {
                error_handle_2(1, line, "mul");
        }

        tmp = *stack;
        if (tmp->next != NULL)
        {
                tmp->next->n = tmp->next->n * tmp->n;
                (*stack) = tmp->next;
                free(tmp);
        }
        else
                error_handle_2(1, line, "mul");
}
