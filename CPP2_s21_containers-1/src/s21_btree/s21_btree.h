#ifndef CPP2_S21_CONTAINERS_1_S21_BTREE_H_
#define CPP2_S21_CONTAINERS_1_S21_BTREE_H_

#include <iostream>
#include <limits>

#include "s21_bt_iterator.h"
#include "s21_bt_node.h"

namespace s21 {

template <typename K, typename T>
class BinaryTree {
 public:
  // BinaryTree member type
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = BTIterator<K, T>;
  using const_iterator = BTConstIterator<K, T>;
  using size_type = size_t;

  // BinaryTree member functions
  BinaryTree();
  BinaryTree(std::initializer_list<value_type> const& items);
  BinaryTree(const BinaryTree& b_tree);
  BinaryTree(BinaryTree&& b_tree);
  ~BinaryTree();
  BinaryTree& operator=(BinaryTree&& b_tree);

  // BinaryTree iterators
  [[nodiscard]] iterator begin();
  [[nodiscard]] const_iterator cbegin() const;
  [[nodiscard]] iterator end();
  [[nodiscard]] const_iterator cend() const;

  // BinaryTree capacity
  bool empty();
  [[nodiscard]] size_type size() const;
  [[nodiscard]] size_type max_size() const;

  // BinaryTree modifiers
  void clear();
  std::pair<iterator, bool> insert(const_reference value);
  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj);
  void erase(iterator pos);
  void swap(BinaryTree& other);
  void merge(const BinaryTree& other);

  // BinaryTree lookup
  [[nodiscard]] iterator find(const key_type& key);
  [[nodiscard]] bool contains(const key_type& key);
  void print_tree();

 protected:
  // BinaryTree fields
  BTNode<K, T>* root_;
  BTNode<K, T>* nil_;
  BTNode<K, T>* min_;
  BTNode<K, T>* max_;
  size_type size_;

  // Sub-methods
  bool find_insert_place(const key_type& key, iterator& it);
  void node_insertion(iterator it, BTNode<K, T>* node);
  void clear_branch(iterator pos);
  void insert_balance(iterator pos);
  void erase_balance(iterator& pos);
  void right_rotate(iterator pos);
  void left_rotate(iterator pos);
  void insert_case_1(iterator pos);
  void insert_case_2(iterator pos);
  void erase_case_1(iterator pos);
  void erase_case_1_a(iterator pos);
  void erase_case_1_b(iterator pos);
  void erase_case_1_c(iterator pos);
  void erase_case_2(iterator pos);
  void erase_case_3(iterator& pos);
  void move_root(BTNode<K, T>* old_root, BTNode<K, T>* new_root);
  void red_nephew_rotations(iterator pos);
  void print_layer(int left_offset, size_type depth_to_print);
  void print_childs(iterator pos, int left_offset);
  size_type count_width(iterator pos);
  size_type depth(iterator pos);
};

}  // namespace s21

#include "s21_btree.tpp"

#endif  // CPP2_S21_CONTAINERS_1_S21_BTREE_H_