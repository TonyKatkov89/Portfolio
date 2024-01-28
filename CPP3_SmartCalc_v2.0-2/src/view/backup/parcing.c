#include "parcing.h"

stack_s *parcing(char *input) {
  stack_s *notation = initializing();
  stack_s *operators = initializing();
  char *beg = input;
  for (int k = 0; *input && k < MAX_SIZE - 1; k++) {
    if (is_operator(beg, input)) {
      char operator[2] = {*input, '\0'};
      particle_allocation(operator, notation, operators);
      input++;
    } else if (*input == '-') {
      particle_allocation("~", notation, operators);
      input++;
    } else if (*input == '+') {
      particle_allocation("&", notation, operators);
      input++;
    } else if (is_digit(input)) {
      number_allocation(&input, notation, operators);
    } else if (*input == ' ') {
      input++;
    } else {
      char operator[MAX_SIZE] = {0};
      for (int i = 0; is_letter_not_x(input) && i < MAX_SIZE - 1; i++) {
        operator[i] = * input;
        input++;
      }
      particle_allocation(operator, notation, operators);
    }
  }
  operators_to_notation(notation, operators);
  free(operators);
  return notation;
}

void particle_allocation(char *input, stack_s *notation, stack_s *operators) {
  if (!strcmp(input, "x") || !strcmp(input, "X")) {
    push(operators, input, OPERATOR);
    pop(operators, notation);
  } else if (!strcmp(input, ")")) {
    closing_bracket(notation, operators);
  } else if (operators->size == 0 || !strcmp(input, "(") ||
             operators_priority(
                 input, operators->elements[operators->size - 1]) == 1) {
    push(operators, input, OPERATOR);
  } else {
    low_priority(input, notation, operators);
  }
}

int operators_priority(char *input, char *on_stack) {
  int pr = -1;
  if (priority(input) > priority(on_stack)) {
    pr = 1;
  }
  return pr;
}

int priority(char *input) {
  int priority = 0;
  if (!strcmp(input, "+") || !strcmp(input, "-")) {
    priority = 1;
  } else if (!strcmp(input, "*") || !strcmp(input, "/")) {
    priority = 2;
  } else if (!strcmp(input, "~") || !strcmp(input, "&") ||
             !strcmp(input, "sin") || !strcmp(input, "cos") ||
             !strcmp(input, "tan") || !strcmp(input, "ctg") ||
             !strcmp(input, "sqrt") || !strcmp(input, "ln") ||
             !strcmp(input, "mod") || !strcmp(input, "log") ||
             !strcmp(input, "acos") || !strcmp(input, "asin") ||
             !strcmp(input, "atan")) {
    priority = 3;
  } else if (!strcmp(input, "#")) {
    priority = 4;
  } else if (!strcmp(input, "^")) {
    priority = 5;
  }
  return priority;
}

void closing_bracket(stack_s *notation, stack_s *operators) {
  while (operators->size > 0 &&
         strcmp(operators->elements[operators->size - 1], "(")) {
    pop(operators, notation);
  }
  discard_top(operators);
}

void low_priority(char *input, stack_s *notation, stack_s *operators) {
  while (operators->size > 0 &&
         operators_priority(input, operators->elements[operators->size - 1]) ==
             -1) {
    pop(operators, notation);
  }
  push(operators, input, OPERATOR);
}

void operators_to_notation(stack_s *notation, stack_s *operators) {
  while (operators->size != 0) {
    if (!strcmp(operators->elements[operators->size - 1], "(")) {
      discard_top(operators);
    } else {
      pop(operators, notation);
    }
  }
}

int is_operator(const char *beg, const char *c) {
  int symbol_is_minus =
      *c == '-' && c != beg && (is_digit(c - 1) || *(c - 1) == ')' || is_x(c - 1));
  int symbol_is_plus =
      *c == '+' && c != beg && (is_digit(c - 1) || *(c - 1) == ')' || is_x(c - 1));
  int symbol_is_operator = is_x(c) || *c == '*' || *c == '/' ||
                           *c == '(' || *c == ')' || *c == '^' ||
                           symbol_is_minus || symbol_is_plus;
  return symbol_is_operator;
}

int is_digit(const char *c) { return *c >= '0' && *c <= '9'; }

int is_letter(const char *c) {
  int is_lower = *c >= 'a' && *c <= 'z';
  int is_upper = *c >= 'A' && *c <= 'Z';
  return (is_lower || is_upper);
}

int is_letter_not_x(const char *c) {
  int not_x = *c != 'x' && *c != 'X';
  return is_letter(c) && not_x;
}

int is_x(const char *c) {
  return *c == 'x' || *c == 'X';
}
void number_allocation(char **input, stack_s *notation, stack_s *operators) {
  char number[MAX_SIZE] = {0};
  number[0] = **input;
  (*input)++;
  for (int i = 1; (is_digit(*input) || **input == '.' || **input == ',') &&
                  i < MAX_SIZE - 1;
       i++) {
    number[i] = **input;
    (*input)++;
  }
  push(notation, number, NUMBER);
  if (**input == 'X' || **input == 'x') {
    particle_allocation("#", notation, operators);
    particle_allocation("x", notation, operators);
    (*input)++;
  }
}
