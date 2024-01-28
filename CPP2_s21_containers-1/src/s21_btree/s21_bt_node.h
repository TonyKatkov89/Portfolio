#ifndef CPP2_S21_CONTAINERS_1_S21_BT_NODE_H_
#define CPP2_S21_CONTAINERS_1_S21_BT_NODE_H_

#include <iostream>

#include "s21_btree.h"

namespace s21 {

template <typename K, typename T>
struct BTNode {
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = size_t;
  char color_;
  std::pair<const K, T> obj_;
  BTNode<K, T>* parent_;
  BTNode<K, T>* left_;
  BTNode<K, T>* right_;

  BTNode(const BTNode* parent, BTNode* nil);
  BTNode(char color, BTNode* parent, BTNode* nil);
  BTNode(char color, const key_type& key, const mapped_type& value,
         BTNode* parent, BTNode* nil);
  BTNode(char color, const value_type& obj, BTNode* parent, BTNode* nil);
  ~BTNode();

  bool operator==(const BTNode<K, T>& other);
  bool operator!=(const BTNode<K, T>& other);

  void change_color();
};

}  // namespace s21

#include "s21_bt_node.tpp"

#endif  // CPP2_S21_CONTAINERS_1_S21_BT_NODE_H_