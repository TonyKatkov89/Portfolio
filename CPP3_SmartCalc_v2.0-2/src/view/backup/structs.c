#include "structs.h"

stack_s *initializing() {
  stack_s *stack = (stack_s *)calloc(1, sizeof(stack_s));
  stack->size = 0;
  return stack;
}

void push(stack_s *top, char *input, lex_type_e type) {
  if (top->size < MAX_SIZE) {
    top->elements[top->size] = calloc(MAX_SIZE, sizeof(char));
    strcpy(top->elements[top->size], input);
    top->type[top->size] = type;
    top->size++;
  }
}

void pop(stack_s *top, stack_s *target) {
  if (top->size > 0) {
    target->elements[target->size] = calloc(MAX_SIZE, sizeof(char));
    strcpy(target->elements[target->size], top->elements[top->size - 1]);
    target->type[target->size] = top->type[top->size - 1];
    target->size++;
    free(top->elements[top->size - 1]);
    top->size--;
  }
}

void discard_top(stack_s *top) {
  if (top->size > 0) {
    free(top->elements[top->size - 1]);
    top->size--;
  }
}

num_stack_s *initializing_num() {
  num_stack_s *tmp = (num_stack_s *)calloc(1, sizeof(num_stack_s));
  tmp->size = 0;
  return tmp;
}

void push_num(num_stack_s *top, double num) {
  if (top->size < MAX_SIZE) {
    top->number[top->size] = num;
    top->size++;
  }
}

double pop_num(num_stack_s *top) {
  double number = NAN;
  if (top->size > 0) {
    number = top->number[top->size - 1];
    top->size--;
  }
  return number;
}

void free_stack(stack_s *top) {
  for (int i = 0; i < top->size; i++) {
    free(top->elements[i]);
  }
  free(top);
}
