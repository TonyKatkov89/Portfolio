#ifndef SRC_S21_LIST_ITERATORS_H_
#define SRC_S21_LIST_ITERATORS_H_

#include "iostream"

namespace s21 {

template <typename T>
class list;

template <typename T>
struct ListNode {
  T value_;
  ListNode<T> *next_;
  ListNode<T> *prev_;

  ListNode() noexcept : value_(), next_(nullptr), prev_(nullptr) {}
  explicit ListNode(const T &value)
      : value_(value), next_(nullptr), prev_(nullptr) {}
  void RelinkNode(ListNode<T> *new_prev, ListNode<T> *new_next) noexcept {
    ListNode<T> *prev_node = this->prev_;
    ListNode<T> *next_node = this->next_;
    prev_node->next_ = next_node;
    next_node->prev_ = prev_node;
    this->prev_ = new_prev;
    this->next_ = new_next;
  }
};

// Const Iterator
template <typename T>
class ListConstIterator {
 public:
  friend class list<T>;
  using node = ListNode<T>;
  ListConstIterator() noexcept : current_(nullptr) {}
  explicit ListConstIterator(node *ptr) : current_(ptr) {}
  ListConstIterator(const ListConstIterator &other)
      : current_(other.current_) {}
  ListConstIterator(ListConstIterator &&other) noexcept {
    if (this != &other) {
      current_ = std::move(other.current_);
      other.current_ = nullptr;
    }
  }
  ~ListConstIterator() noexcept {}

  [[nodiscard]] const T &operator*() noexcept { return current_->value_; }
  [[nodiscard]] const T *operator->() noexcept { return &(current_->value_); }
  [[nodiscard]] const T &operator*() const noexcept { return current_->value_; }
  [[nodiscard]] const T *operator->() const noexcept {
    return &(current_->value_);
  }

  ListConstIterator &operator++() noexcept {
    if (current_) {
      current_ = current_->next_;
    }
    return *this;
  }
  ListConstIterator operator++(int) noexcept {
    ListConstIterator<T> temp(*this);
    if (current_) {
      current_ = current_->next_;
    }
    return temp;
  }

  ListConstIterator &operator--() noexcept {
    if (current_) {
      current_ = current_->prev_;
    }
    return *this;
  }
  ListConstIterator operator--(int) noexcept {
    ListConstIterator<T> temp(*this);
    if (current_) {
      current_ = current_->prev_;
    }
    return temp;
  }

  [[nodiscard]] bool operator==(
      const ListConstIterator<T> &other) const noexcept {
    return current_ == other.current_;
  }
  [[nodiscard]] bool operator!=(
      const ListConstIterator<T> &other) const noexcept {
    return current_ != other.current_;
  }

 protected:
  node *current_;
};

// Iterator
template <typename T>
class ListIterator : public ListConstIterator<T> {
 public:
  using typename ListConstIterator<T>::node;
  using ListConstIterator<T>::ListConstIterator;
  ListIterator() noexcept : ListConstIterator<T>() {}
  explicit ListIterator(node *ptr) : ListConstIterator<T>(ptr) {}
  ListIterator(const ListIterator &other) : ListConstIterator<T>(other) {}
  ListIterator(ListIterator &&other) noexcept
      : ListConstIterator<T>(std::move(other)) {}
  ~ListIterator() noexcept {}

  ListIterator &operator=(const ListIterator<T> &other) noexcept {
    this->current_ = other.current_;
    return *this;
  }

  [[nodiscard]] T &operator*() noexcept { return this->current_->value_; }
  [[nodiscard]] T *operator->() noexcept { return &(this->current_->value_); }
  [[nodiscard]] T &operator*() const noexcept { return this->current_->value_; }
  [[nodiscard]] T *operator->() const noexcept {
    return &(this->current_->value_);
  }
};

}  // namespace s21

#endif  //  SRC_S21_LIST_ITERATORS_H_
