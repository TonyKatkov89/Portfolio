#include "calculation.h"

stack_s *notation_reverse(stack_s *stack, double a) {
  stack_s *tmp = initializing();
  stack_s *result = initializing();
  for (int i = 0; i < stack->size; i++) {
    tmp->elements[i] = calloc(MAX_SIZE, sizeof(char));
    if (!strcmp(stack->elements[i], "x")) {
      sprintf(tmp->elements[i], "%lf", a);
      tmp->type[i] = NUMBER;
    } else {
      strcpy(tmp->elements[i], stack->elements[i]);
      tmp->type[i] = stack->type[i];
    }
    tmp->size++;
  }
  while (tmp->size > 0) {
    pop(tmp, result);
  }
  free(tmp);
  return result;
}

double calculate(stack_s *notation) {
  int error = 0;
  num_stack_s *numbers = initializing_num();
  for (int i = notation->size - 1; i >= 0; i--) {
    if (notation->type[i] == NUMBER) {
      double temp_num;
      sscanf(notation->elements[i], "%lf", &temp_num);
      push_num(numbers, temp_num);
    } else {
      if (run_operation(notation->elements[i], numbers) == 1) {
        error = 1;
      }
    }
    discard_top(notation);
  }
  double result;
  if (error || numbers->size < 1) {
    result = NAN;
  } else {
    result = pop_num(numbers);
  }
  free(numbers);
  return result;
}

int run_operation(char *operation, num_stack_s *numbers) {
  int error = 0;
  if (numbers->size > 0) {
    double a = pop_num(numbers);
    double result = 0;
    if (!strcmp(operation, "~")) {
      result -= a;
    } else if (!strcmp(operation, "&")) {
      result = a;
    } else if (!strcmp(operation, "sin")) {
      result = sin(a);
    } else if (!strcmp(operation, "cos")) {
      result = cos(a);
    } else if (!strcmp(operation, "tan")) {
      result = tan(a);
    } else if (!strcmp(operation, "asin")) {
      result = asin(a);
    } else if (!strcmp(operation, "acos")) {
      result = acos(a);
    } else if (!strcmp(operation, "atan")) {
      result = atan(a);
    } else if (!strcmp(operation, "ctg")) {
      result = cos(a) / sin(a);
    } else if (!strcmp(operation, "sqrt")) {
      if (a < 0) {
        error = 1;
        result = 0;
      } else {
        result = sqrt(a);
      }
    } else if (!strcmp(operation, "ln")) {
      result = log(a);
    } else if (!strcmp(operation, "log")) {
      result = log10(a);
    } else if (!strcmp(operation, "-")) {
      double b = pop_num(numbers);
      result = b - a;
    } else if (!strcmp(operation, "*") || !strcmp(operation, "#")) {
      double b = pop_num(numbers);
      result = b * a;
    } else if (!strcmp(operation, "/")) {
      if (a == 0) {
        error = 1;
        result = 0;
      } else {
        double b = pop_num(numbers);
        result = b / a;
      }
    } else if (!strcmp(operation, "mod")) {
      if (a == 0) {
        error = 1;
        result = 0;
      } else {
        double b = pop_num(numbers);
        result = fmod(b, a);
      }
    } else if (!strcmp(operation, "+")) {
      double b = pop_num(numbers);
      result = b + a;
    } else if (!strcmp(operation, "^")) {
      double b = pop_num(numbers);
      result = pow(b, a);
    } else {
      error = 1;
    }
    push_num(numbers, result);
  } else {
    error = 1;
  }
  return error;
}

double annuity_payment(double s, double p, double n) {
  p = p / 12;
  double monthly_payment;
  if (p == 0) {
    monthly_payment = s / n;
  } else {
    monthly_payment = s * p * pow((1 + p), n) / (pow((1 + p), n) - 1);
  }
  return monthly_payment;
}

// double differentiated_interest(double s, double p, double n, int md, int yd)
// {
//   // double monthly_payment = s / n + (s * p * md) / yd;
//   double monthly_payment = (s * p * md) / yd;
//   return monthly_payment;
// }

double interest_sum(double s, double p) {
  p = p / 12;
  double percents_sum = s * p;
  return percents_sum;
}
