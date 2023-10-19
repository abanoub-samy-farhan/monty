#include "monty.h"

stack_t *head = NULL;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_f(argv[1]);
	free_nodes();
	return (0);
}

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_handle(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
