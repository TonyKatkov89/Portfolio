#ifndef SRC_S21_QUEUE_S21_QUEUE_H_
#define SRC_S21_QUEUE_S21_QUEUE_H_

#include "../s21_list/s21_list.h"

namespace s21 {
template <typename T>
class queue {
 public:
  // Queue Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  // Queue Member functions
  queue() noexcept : list_queue() {}
  explicit queue(std::initializer_list<value_type> const &items)
      : list_queue{items} {}
  queue(const queue &q) : list_queue(q.list_queue) {}
  queue(queue &&q) noexcept : list_queue(std::move(q.list_queue)) {}
  ~queue() {}
  queue &operator=(queue &&q) noexcept {
    this->list_queue = std::move(q.list_queue);
    return *this;
  }

  // Queue Element access
  [[nodiscard]] const_reference front() noexcept { return list_queue.front(); }
  [[nodiscard]] const_reference back() noexcept { return list_queue.back(); }

  // Queue Capacity
  [[nodiscard]] bool empty() const noexcept { return list_queue.empty(); }
  [[nodiscard]] size_type size() const noexcept { return list_queue.size(); }

  // Queue Modifiers
  void push(const_reference value) { list_queue.push_back(value); }
  void pop() { list_queue.pop_front(); }
  void swap(queue &other) noexcept { list_queue.swap(other.list_queue); }
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    list_queue.insert_many_back(args...);
  }

 private:
  list<T> list_queue;
};
}  // namespace s21
#endif  // SRC_S21_QUEUE_S21_QUEUE_H_
