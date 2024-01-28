#ifndef SRC_S21_STACK_S21_STACK_H_
#define SRC_S21_STACK_S21_STACK_H_

#include "../s21_list/s21_list.h"

namespace s21 {
template <typename T>
class stack {
 public:
  // Stack Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Stack Member functions
  stack() noexcept : list_stack() {}
  explicit stack(std::initializer_list<value_type> const &items)
      : list_stack{items} {}
  stack(const stack &s) : list_stack(s.list_stack) {}
  stack(stack &&s) noexcept : list_stack(std::move(s.list_stack)) {}
  ~stack() noexcept {}
  stack &operator=(stack &&s) noexcept {
    this->list_stack = std::move(s.list_stack);
    return *this;
  }

  // Stack Element access
  [[nodiscard]] const_reference top() noexcept { return list_stack.back(); }

  // Stack Capacity
  [[nodiscard]] bool empty() const noexcept { return list_stack.empty(); }
  [[nodiscard]] size_type size() const noexcept { return list_stack.size(); }

  // Stack Modifiers
  void push(const_reference value) { list_stack.push_back(value); }
  void pop() { list_stack.pop_back(); }
  void swap(stack &other) noexcept { list_stack.swap(other.list_stack); }
  template <typename... Args>
  void insert_many_front(Args &&...args) {
    list_stack.insert_many_back(args...);
  }

 private:
  list<T> list_stack;
};
}  // namespace s21
#endif  // SRC_S21_STACK_S21_STACK_H_
