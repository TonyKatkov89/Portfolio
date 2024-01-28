#ifndef SRC_CALC_CONTROLLER_H
#define SRC_CALC_CONTROLLER_H

#include "../model/calculator.h"

namespace s21 {

class CalcController {
 public:
  CalcController(const std::string& input);
  ~CalcController();

  const std::stack<Lexem>& GetExpression() const;
  double Result(double x);
  static double AnnuityPayment(double s, double p, double n);
  static double InterestSum(double s, double p);

 private:
  Calculator* calc_;
};

}  // namespace s21

#endif  // SRC_CALC_CONTROLLER_H