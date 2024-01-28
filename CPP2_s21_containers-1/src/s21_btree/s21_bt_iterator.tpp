#include "s21_bt_iterator.h"

namespace s21 {

template <typename K, typename T>
BTIterator<K, T>::BTIterator() noexcept : current_(nullptr), nil_(nullptr) {}

template <typename K, typename T>
BTIterator<K, T>::BTIterator(BTNode<K, T>* node, BTNode<K, T>* nil) {
  current_ = node;
  nil_ = nil;
}

template <typename K, typename T>
BTIterator<K, T>::BTIterator(const BTIterator<K, T>& other)
    : current_(other.current_), nil_(other.nil_) {}

template <typename K, typename T>
const typename BTIterator<K, T>::value_type& BTIterator<K, T>::operator*() {
  return current_->obj_;
}

template <typename K, typename T>
const typename BTIterator<K, T>::value_type* BTIterator<K, T>::operator->() {
  return &(current_->obj_);
}

template <typename K, typename T>
BTIterator<K, T>& BTIterator<K, T>::operator++() {
  BTIterator<K, T> next;
  if (current_->right_ != nil_) {
    next = right_son();
    while (next.current_->left_ != nil_) {
      next = next.left_son();
    }
  } else if (is_left()) {
    next = parent();
  } else {
    next = *this;
    while (next.current_->parent_ != nil_ && next.is_right()) {
      next = next.parent();
    }
    if (next.current_->parent_ == nil_) {
      next.current_ = nil_;
    } else {
      next = next.parent();
    }
  }
  current_ = next.current_;
  return *this;
}

template <typename K, typename T>
BTIterator<K, T>& BTIterator<K, T>::operator--() {
  BTIterator<K, T> prev;
  if (current_->right_ != nil_) {
    prev = left_son();
    while (prev.current_->right_ != nil_) {
      prev = prev.right_son();
    }
  } else if (is_right()) {
    prev = parent();
  } else {
    prev = *this;
    while (prev.current_->parent_ == nil_ && prev.is_left()) {
      prev = prev.parent();
    }
    if (prev.current_->parent_ != nil_) {
      prev.current_ = nil_;
    } else {
      prev = prev.parent();
    }
  }
  current_ = prev.current_;
  return *this;
}

template <typename K, typename T>
BTIterator<K, T>& BTIterator<K, T>::operator=(const BTIterator<K, T>& other) {
  this->current_ = other.current_;
  this->nil_ = other.nil_;
  return *this;
}

template <typename K, typename T>
bool BTIterator<K, T>::operator==(const BTIterator<K, T>& other) const {
  return (current_ == other.current_ && nil_ == other.nil_);
}

template <typename K, typename T>
bool BTIterator<K, T>::operator!=(const BTIterator<K, T>& other) const {
  return current_ != other.current_;
}

template <typename K, typename T>
bool BTIterator<K, T>::is_left() {
  return current_->parent_ != nil_ && current_ == current_->parent_->left_;
}

template <typename K, typename T>
bool BTIterator<K, T>::is_right() {
  return current_->parent_ != nil_ && current_ == current_->parent_->right_;
}

template <typename K, typename T>
bool BTIterator<K, T>::has_red_nephew() {
  return (sibling().current_->left_->color_ == 'r' ||
          sibling().current_->right_->color_ == 'r');
}

template <typename K, typename T>
BTIterator<K, T> BTIterator<K, T>::left_son() {
  BTIterator<K, T> it(current_->left_, nil_);
  return it;
}

template <typename K, typename T>
BTIterator<K, T> BTIterator<K, T>::right_son() {
  BTIterator<K, T> it(current_->right_, nil_);
  return it;
}

template <typename K, typename T>
BTIterator<K, T> BTIterator<K, T>::parent() {
  BTIterator<K, T> it(current_->parent_, nil_);
  return it;
}

template <typename K, typename T>
BTIterator<K, T> BTIterator<K, T>::sibling() {
  if (is_right()) {
    BTIterator<K, T> it(parent().left_son().current_, nil_);
    return it;
  } else if (is_left()) {
    BTIterator<K, T> it(parent().right_son().current_, nil_);
    return it;
  } else {
    BTIterator<K, T> it(nil_, nil_);
    return it;
  }
}

template <typename K, typename T>
BTIterator<K, T> BTIterator<K, T>::uncle() {
  BTIterator<K, T> it(parent().sibling().current_, nil_);
  return it;
}

template <typename K, typename T>
BTIterator<K, T> BTIterator<K, T>::grandpa() {
  BTIterator<K, T> it(parent().parent().current_, nil_);
  return it;
}

template <typename K, typename T>
BTConstIterator<K, T>::BTConstIterator(BTNode<K, T>* node, BTNode<K, T>* nil)
    : BTIterator<K, T>() {
  this->current_ = node;
  this->nil_ = nil;
}

template <typename K, typename T>
BTConstIterator<K, T>::BTConstIterator(const BTIterator<K, T>& other)
    : BTIterator<K, T>() {
  this->current_ = other.current_;
  this->nil_ = other.nil_;
}

template <typename K, typename T>
const typename BTConstIterator<K, T>::value_type&
BTConstIterator<K, T>::operator*() {
  return this->current_->obj_;
}

template <typename K, typename T>
const typename BTConstIterator<K, T>::value_type*
BTConstIterator<K, T>::operator->() {
  return &this->current_->obj_;
}

}  // namespace s21