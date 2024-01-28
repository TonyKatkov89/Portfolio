#ifndef SRC_LEXEM_H
#define SRC_LEXEM_H

#include <map>
#include <string>

static std::map<std::string, int> prioritization = {
    {"+", 1},    {"-", 1},    {"*", 2},   {"/", 2},   {"~", 3},
    {"&", 3},    {"sin", 3},  {"cos", 3}, {"tan", 3}, {"ctg", 3},
    {"sqrt", 3}, {"ln", 3},   {"mod", 3}, {"log", 3}, {"asin", 3},
    {"acos", 3}, {"atan", 3}, {"#", 4},   {"^", 5}};

enum LexType {
  OPERATOR,
  NUMBER,
};

class Lexem {
 public:
  Lexem(const std::string& name, LexType type)
      : name_(name), type_(type), priority_(0) {
    if (prioritization.find(name) != prioritization.end()) {
      priority_ = prioritization.find(name)->second;
    }
  };
  Lexem(const Lexem& other) : Lexem(other.name_, other.type_){};
  Lexem(Lexem&& other) : Lexem(other.name_, other.type_){};
  ~Lexem(){};

  const std::string& GetValue() const { return name_; }
  LexType GetType() const { return type_; }
  int GetPriority() const { return priority_; }

 private:
  std::string name_;
  LexType type_;
  int priority_;
};

#endif  // SRC_LEXEM_H
