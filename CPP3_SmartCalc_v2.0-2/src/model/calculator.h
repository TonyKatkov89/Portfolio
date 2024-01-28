#ifndef SRC_PARCING_H
#define SRC_PARCING_H

#include <cmath>
#include <iostream>
#include <limits>
#include <stack>

#include "lexem.h"

namespace s21 {

class Calculator {
 public:
  Calculator(const std::string& input);
  ~Calculator();

  const std::stack<Lexem>& GetExpression() const;
  double Result(double x = 0);
  static double CAnnuityPayment(double s, double p, double n);
  static double CInterestSum(double s, double p);

 private:
  std::stack<Lexem> expression_;

  std::stack<Lexem> Parcing(const std::string& input);
  void ParticleAllocation(std::string lexem, std::stack<Lexem>& notation,
                          std::stack<Lexem>& operators);
  int OperatorsPriority(std::string input, const Lexem& onStack);
  void ClosingBracket(std::stack<Lexem>& notation,
                      std::stack<Lexem>& operators);
  void LowPriority(std::string lexem, std::stack<Lexem>& notation,
                   std::stack<Lexem>& operators);
  void OperatorsToNotation(std::stack<Lexem>& notation,
                           std::stack<Lexem>& operators);
  bool IsOperator(const std::string::const_iterator& beg,
                  const std::string::const_iterator& c);
  bool IsLetterNotX(const std::string::const_iterator& c);
  bool IsX(char c);
  void NumberAllocation(std::string::const_iterator& input,
                        std::stack<Lexem>& notation,
                        std::stack<Lexem>& operators);
  std::stack<Lexem> ReverseNotation(std::stack<Lexem> notation);
  std::stack<Lexem> ReplaceX(const std::stack<Lexem>& notation, double xNumber);
  double Calculate(std::stack<Lexem> notation);
  void RunOperation(const std::string operation, std::stack<double>& numbers);
  std::string RemoveSpaces(std::string input);
};

}  // namespace s21

#endif  // SRC_PARCING_H