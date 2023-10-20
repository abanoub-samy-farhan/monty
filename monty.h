#ifndef MONTY_H
#define MONTY_H

#define MAX_SIZE 1024
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include<stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);



stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);

void excute_fun(op_func func, char *function, char *value, int line);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

void open_f(char *filename);
void extract_line(char *buffer, int line);
void read_f(FILE *);
void find_func(char *, char *, int);

void error_handle(int code, ...);
void error_handle_2(int code, ...);

void add_stack(stack_t **stack, unsigned int line);
void sub_stack(stack_t **stack, unsigned int line);
void div_stack(stack_t **stack, unsigned int line);
void mul_stack(stack_t **stack, unsigned int line);
#endif
