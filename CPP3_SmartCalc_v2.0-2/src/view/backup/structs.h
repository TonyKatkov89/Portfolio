#ifndef STRUCTS_H
#define STRUCTS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef enum lex_type {
  OPERATOR,
  NUMBER,
} lex_type_e;

typedef struct stack {
  char *elements[MAX_SIZE];
  lex_type_e type[MAX_SIZE];
  int size;
} stack_s;

typedef struct num_stack {
  double number[MAX_SIZE];
  int size;
} num_stack_s;

stack_s *initializing();
void push(stack_s *top, char *input, lex_type_e type);
void pop(stack_s *top, stack_s *target);
void discard_top(stack_s *top);
num_stack_s *initializing_num();
void push_num(num_stack_s *top, double num);
double pop_num(num_stack_s *top);
void free_stack(stack_s *top);

#endif
