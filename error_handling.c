#include "monty.h"

void error_handle(int code, ...)
{
	va_list argument;
	char *opcode;
	int n;

	va_start(argument, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argument, char *));
			break;
		case 3:
			n = va_arg(argument, int);
			opcode = va_arg(argument, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argument, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
