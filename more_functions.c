#include "monty.h"

void mod_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL || (*stack) == NULL)
	{
		error_handle_2(1, line, "mod");
	}

	tmp = *stack;
	if (tmp->next == NULL || tmp->n == 0)
	{
		tmp->n == 0 ? error_handle_2(2, line) : error_handle_2(1, line, "mod");
	}
	else
	{
		tmp->next->n = tmp->next->n % tmp->n;
		(*stack) = tmp->next;
		free(tmp);
	}
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
