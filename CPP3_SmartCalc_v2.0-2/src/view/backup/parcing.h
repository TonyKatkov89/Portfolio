#ifndef PARCING_H
#define PARCING_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

//#define PRIORITY1 "+-"
//#define PRIORITY2 "*/"
//#define PRIORITY3 "~sincostanctgsqrtlnlog"

stack_s *parcing(char *input);
void particle_allocation(char *input, stack_s *notation, stack_s *operators);
int operators_priority(char *input, char *on_stack);
int priority(char *input);
void closing_bracket(stack_s *notation, stack_s *operators);
void low_priority(char *input, stack_s *notation, stack_s *operators);
void operators_to_notation(stack_s *notation, stack_s *operators);
int is_operator(const char *beg, const char *c);
int is_digit(const char *c);
int is_letter(const char *c);
int is_letter_not_x(const char *c);
int is_x(const char *c);
void number_allocation(char **input, stack_s *notation, stack_s *operators);

#endif
