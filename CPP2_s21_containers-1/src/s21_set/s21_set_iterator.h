#ifndef CPP2_S21_CONTAINERS_1_S21_SET_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_S21_SET_ITERATOR_H_

#include <iostream>

#include "../s21_btree/s21_bt_iterator.h"

namespace s21 {

template <typename K, typename T = K>
class SetIterator : public BTIterator<K, T> {
 public:
  // using T = K;
  using key_type = K;
  using mapped_type = T;
  using value_type = K;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;

  SetIterator() : BTIterator<K, T>() {}
  SetIterator(BTNode<K, T>* node, BTNode<K, T>* nil)
      : BTIterator<K, T>(node, nil) {}
  SetIterator(const SetIterator<K, T>& other) : BTIterator<K, T>() {
    this->current_ = other.current_;
    this->nil_ = other.nil_;
  }

  const value_type& operator*() { return this->current_->obj_.first; }
  const value_type* operator->() { return &(this->current_->obj_.first); }
};

template <typename K, typename T>
class SetConstIterator : public SetIterator<K, T> {
 public:
  const typename SetConstIterator<K, T>::value_type& operator*();
  const typename SetConstIterator<K, T>::value_type* operator->();
  SetConstIterator<K, T>& operator=(const SetIterator<K, T>& other);
  SetConstIterator<K, T>& operator=(const SetConstIterator<K, T>& other);
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_S21_SET_ITERATOR_H_