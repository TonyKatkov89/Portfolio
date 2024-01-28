#ifndef SRC_S21_LIST_S21_LIST_H_
#define SRC_S21_LIST_S21_LIST_H_

#include <iostream>
#include <limits>

#include "iterators.h"

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using node = ListNode<T>;
  using const_iterator = ListConstIterator<T>;
  using iterator = ListIterator<T>;

  // List Functions (constructors && destructor)
  list() noexcept;
  explicit list(size_type n);
  explicit list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l) noexcept;
  ~list() noexcept;
  list &operator=(list &&l) noexcept;

  // List Element access
  [[nodiscard]] const_reference front() noexcept;
  [[nodiscard]] const_reference back() noexcept;

  // List Iterators
  [[nodiscard]] iterator begin() noexcept;
  [[nodiscard]] iterator end() noexcept;
  [[nodiscard]] const_iterator cbegin() const noexcept;
  [[nodiscard]] const_iterator cend() const noexcept;

  // List Capacity
  [[nodiscard]] bool empty() const noexcept;
  [[nodiscard]] size_type size() const noexcept;
  [[nodiscard]] size_type max_size() const noexcept;

  // List Modifiers
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other) noexcept;
  void merge(list &other);
  void splice(const_iterator pos, list &other);
  void reverse() noexcept;
  void unique();
  void sort();
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  node *dummy_node_;
  size_type size_;
  void DummyLinker(node *new_node) noexcept;
  void SplitList(list &a, list &b) noexcept;
  void InsertFront();
  template <typename Arg, typename... Rest>
  void InsertFront(Arg &&arg, Rest &&...rest);
};

}  // namespace s21
#include "s21_list.tpp"
#endif  //  SRC_S21_LIST_S21_LIST_H_
