#include "monty.h"

void free_nodes(void)
{
	stack_t *buff;

	while(head)
	{
		buff = head;
		head = head->next;
		free(buff);
	}
}
