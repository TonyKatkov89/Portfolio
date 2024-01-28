#include "calculator.h"

static size_t MAX_SIZE = 256;

namespace s21 {

Calculator::Calculator(const std::string& input)
    : expression_(Parcing(input)) {}

Calculator::~Calculator(){};

const std::stack<Lexem>& Calculator::GetExpression() const {
  return expression_;
}

double Calculator::Result(double x) {
  double result;
  try {
    result = Calculate(ReplaceX(expression_, x));
  } catch (const std::underflow_error& uf_error) {
    std::cerr << uf_error.what() << std::endl;
    result = std::numeric_limits<double>::quiet_NaN();
  } catch (const std::logic_error& log_error) {
    std::cerr << log_error.what() << std::endl;
    result = std::numeric_limits<double>::quiet_NaN();
  } catch (const std::overflow_error& of_error) {
    std::cerr << of_error.what() << std::endl;
    result = std::numeric_limits<double>::quiet_NaN();
  }
  return result;
}

std::stack<Lexem> Calculator::Parcing(const std::string& input) {
  if (input.length() > MAX_SIZE) {
    throw std::overflow_error("The input is longer than 256 symbols.");
  }
  std::string noSpacesInput = RemoveSpaces(input);
  std::stack<Lexem> notation;
  std::stack<Lexem> operators;
  std::string::const_iterator beg = noSpacesInput.begin();
  for (std::string::const_iterator symbolPos = noSpacesInput.begin();
       symbolPos < noSpacesInput.end();) {
    if (IsOperator(beg, symbolPos)) {
      std::string operation = {*symbolPos};
      ParticleAllocation(operation, notation, operators);
      ++symbolPos;
    } else if (*symbolPos == '-') {
      ParticleAllocation("~", notation, operators);
      ++symbolPos;
    } else if (*symbolPos == '+') {
      ParticleAllocation("&", notation, operators);
      ++symbolPos;
    } else if (std::isdigit(*symbolPos)) {
      NumberAllocation(symbolPos, notation, operators);
    } else if (*symbolPos == ' ') {
      ++symbolPos;
    } else {
      std::string operation = {""};
      do {
        operation.append({*symbolPos});
        ++symbolPos;
      } while (IsLetterNotX(symbolPos));
      ParticleAllocation(operation, notation, operators);
    }
  }
  OperatorsToNotation(notation, operators);
  return notation;
}

void Calculator::ParticleAllocation(std::string lexem,
                                    std::stack<Lexem>& notation,
                                    std::stack<Lexem>& operators) {
  if (lexem == "x" || lexem == "X") {
    notation.push({lexem, OPERATOR});
  } else if (lexem == ")") {
    ClosingBracket(notation, operators);
  } else if (operators.size() == 0 || lexem == "(" ||
             OperatorsPriority(lexem, operators.top()) == 1) {
    operators.push({lexem, OPERATOR});
  } else {
    LowPriority(lexem, notation, operators);
  }
}

int Calculator::OperatorsPriority(std::string input, const Lexem& onStack) {
  int pr = -1;
  if (prioritization.find(input)->second > onStack.GetPriority()) {
    pr = 1;
  }
  return pr;
}

void Calculator::ClosingBracket(std::stack<Lexem>& notation,
                                std::stack<Lexem>& operators) {
  while (operators.size() > 0 && operators.top().GetValue() != "(") {
    notation.push(operators.top());
    operators.pop();
  }
  operators.pop();
}

void Calculator::LowPriority(std::string lexem, std::stack<Lexem>& notation,
                             std::stack<Lexem>& operators) {
  while (operators.size() > 0 &&
         OperatorsPriority(lexem, operators.top()) == -1) {
    notation.push(operators.top());
    operators.pop();
  }
  operators.push({lexem, OPERATOR});
}

void Calculator::OperatorsToNotation(std::stack<Lexem>& notation,
                                     std::stack<Lexem>& operators) {
  while (operators.size() > 0) {
    if (operators.top().GetValue() == "(") {
      operators.pop();
    } else {
      notation.push(operators.top());
      operators.pop();
    }
  }
}

bool Calculator::IsOperator(const std::string::const_iterator& beg,
                            const std::string::const_iterator& c) {
  bool symbolIsMinus =
      *c == '-' && c != beg &&
      (std::isdigit(*(c - 1)) || *(c - 1) == ')' || IsX(*(c - 1)));
  bool symbolIsPlus =
      *c == '+' && c != beg &&
      (std::isdigit(*(c - 1)) || *(c - 1) == ')' || IsX(*(c - 1)));
  bool symbolIsOperator = IsX(*c) || *c == '*' || *c == '/' || *c == '(' ||
                          *c == ')' || *c == '^' || symbolIsMinus ||
                          symbolIsPlus;
  return symbolIsOperator;
}

bool Calculator::IsLetterNotX(const std::string::const_iterator& c) {
  int not_x = *c != 'x' && *c != 'X';
  return std::isalpha(*c) && not_x;
}

bool Calculator::IsX(char c) { return c == 'x' || c == 'X'; }

void Calculator::NumberAllocation(std::string::const_iterator& input,
                                  std::stack<Lexem>& notation,
                                  std::stack<Lexem>& operators) {
  std::string number = {""};
  number.append({*input});
  input++;
  while (std::isdigit(*input) || *input == '.' || *input == ',') {
    number.append({*input});
    input++;
  }
  notation.push({number, NUMBER});
  if (*input == 'X' || *input == 'x') {
    ParticleAllocation("#", notation, operators);
    ParticleAllocation("x", notation, operators);
    input++;
  }
}

std::stack<Lexem> Calculator::ReplaceX(const std::stack<Lexem>& notation,
                                       double xNumber) {
  std::stack<Lexem> revStack = notation;
  std::stack<Lexem> resultExp;
  for (size_t i = revStack.size(); i > 0; --i) {
    if (revStack.top().GetValue() == "x") {
      char buffer[MAX_SIZE];
      sprintf(buffer, "%lf", xNumber);
      resultExp.push({buffer, NUMBER});
    } else {
      resultExp.push(revStack.top());
    }
    revStack.pop();
  }
  return resultExp;
}

double Calculator::Calculate(std::stack<Lexem> notation) {
  std::stack<double> numbers;
  double result = 0;
  if (!notation.empty()) {
    for (int i = notation.size(); i > 0; i--) {
      if (notation.top().GetType() == NUMBER) {
        numbers.push(std::stod(notation.top().GetValue()));
      } else {
        RunOperation(notation.top().GetValue(), numbers);
      }
      notation.pop();
    }
  } else {
    throw std::underflow_error("The expression is empty.");
  }
  if (!std::isnan(result)) {
    result = numbers.top();
    numbers.pop();
  }
  return result;
}

void Calculator::RunOperation(const std::string operation,
                              std::stack<double>& numbers) {
  if (numbers.empty()) {
    throw std::logic_error("No arguments for the operation.");
  }
  double a = numbers.top();
  numbers.pop();
  double result = 0;
  if (operation == "~") {
    result -= a;
  } else if (operation == "&") {
    result = a;
  } else if (operation == "sin") {
    result = sin(a);
  } else if (operation == "cos") {
    result = cos(a);
  } else if (operation == "tan") {
    result = tan(a);
  } else if (operation == "asin") {
    result = asin(a);
  } else if (operation == "acos") {
    result = acos(a);
  } else if (operation == "atan") {
    result = atan(a);
  } else if (operation == "ctg") {
    result = cos(a) / sin(a);
  } else if (operation == "sqrt") {
    if (a < 0) {
      throw std::logic_error("Square root from negfative number.");
    } else {
      result = sqrt(a);
    }
  } else if (operation == "ln") {
    result = log(a);
  } else if (operation == "log") {
    result = log10(a);
  } else if (numbers.empty()) {
    throw std::logic_error("No arguments for the operation.");
  } else if (operation == "-") {
    double b = numbers.top();
    numbers.pop();
    result = b - a;
  } else if (operation == "*" || operation == "#") {
    double b = numbers.top();
    numbers.pop();
    result = b * a;
  } else if (operation == "/") {
    if (a == 0) {
      result = 0;
      throw std::logic_error("Division by 0.");
    }
    double b = numbers.top();
    numbers.pop();
    result = b / a;
  } else if (operation == "mod") {
    if (a == 0) {
      result = 0;
      throw std::logic_error("Division by 0.");
    } else {
      double b = numbers.top();
      numbers.pop();
      result = fmod(b, a);
    }
  } else if (operation == "+") {
    double b = numbers.top();
    numbers.pop();
    result = b + a;
  } else if (operation == "^") {
    double b = numbers.top();
    numbers.pop();
    result = pow(b, a);
  } else {
    throw std::logic_error("Incorrect operator.");
  }
  numbers.push(result);
}

double Calculator::CAnnuityPayment(double s, double p, double n) {
  p = p / 12;
  double monthly_payment;
  if (p == 0) {
    monthly_payment = s / n;
  } else {
    monthly_payment = s * p * pow((1 + p), n) / (pow((1 + p), n) - 1);
  }
  return monthly_payment;
}

double Calculator::CInterestSum(double s, double p) {
  p = p / 12;
  double percents_sum = s * p;
  return percents_sum;
}

std::string Calculator::RemoveSpaces(std::string input) {
  for (size_t i = 0; i < input.length(); i++) {
    if (input[i] == ' ') {
      input.erase(i, 1);
      i--;
    }
  }
  return input;
}

}  // namespace s21