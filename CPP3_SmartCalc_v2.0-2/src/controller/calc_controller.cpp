#include "calc_controller.h"

namespace s21 {

CalcController::CalcController(const std::string& input)
    : calc_(new Calculator(input)) {}

CalcController::~CalcController() { delete calc_; }

const std::stack<Lexem>& CalcController::GetExpression() const {
  return calc_->GetExpression();
}

double CalcController::Result(double x) { return calc_->Result(x); }

double CalcController::AnnuityPayment(double s, double p, double n) {
  return Calculator::CAnnuityPayment(s, p, n);
}

double CalcController::InterestSum(double s, double p) {
  return Calculator::CInterestSum(s, p);
}

}  // namespace s21