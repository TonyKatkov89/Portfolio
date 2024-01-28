#ifndef CPP2_S21_CONTAINERS_1_S21_BT_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_S21_BT_ITERATOR_H_

#include <iostream>

#include "s21_bt_node.h"
#include "s21_btree.h"

namespace s21 {

template <typename K, typename T>
class BTIterator {
 public:
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  BTNode<K, T>* current_;
  BTNode<K, T>* nil_;

  BTIterator() noexcept;
  BTIterator(BTNode<K, T>* node, BTNode<K, T>* nil);
  BTIterator(const BTIterator<K, T>& other);

  [[nodiscard]] const value_type& operator*();
  [[nodiscard]] const value_type* operator->();
  BTIterator<K, T>& operator++();
  BTIterator<K, T>& operator--();
  BTIterator<K, T>& operator=(const BTIterator<K, T>& other);
  bool operator==(const BTIterator<K, T>& other) const;
  bool operator!=(const BTIterator<K, T>& other) const;

  [[nodiscard]] bool is_left();
  [[nodiscard]] bool is_right();
  [[nodiscard]] bool has_red_nephew();
  [[nodiscard]] BTIterator<K, T> left_son();
  [[nodiscard]] BTIterator<K, T> right_son();
  [[nodiscard]] BTIterator<K, T> parent();
  [[nodiscard]] BTIterator<K, T> sibling();
  [[nodiscard]] BTIterator<K, T> uncle();
  [[nodiscard]] BTIterator<K, T> grandpa();
};

template <typename K, typename T>
class BTConstIterator : public BTIterator<K, T> {
 public:
  BTConstIterator() : BTIterator<K, T>() {}
  BTConstIterator(BTNode<K, T>* node, BTNode<K, T>* nil);
  BTConstIterator(const BTIterator<K, T>& other);

  const typename BTConstIterator<K, T>::value_type& operator*();
  const typename BTConstIterator<K, T>::value_type* operator->();
  BTConstIterator<K, T>& operator=(const BTIterator<K, T>& other);
  BTConstIterator<K, T>& operator=(const BTConstIterator<K, T>& other);
};

}  // namespace s21

#include "s21_bt_iterator.tpp"

#endif  // CPP2_S21_CONTAINERS_1_S21_BT_ITERATOR_H_