#include "s21_btree.h"

namespace s21 {

// BinaryTree member functions
template <typename K, typename T>
BinaryTree<K, T>::BinaryTree() {
  BTNode<K, T>* nil = new BTNode<K, T>('b', nullptr, nullptr);
  nil->left_ = nil->right_ = nil->parent_ = nil;
  root_ = nil_ = max_ = min_ = nil;
  size_ = 0;
}

template <typename K, typename T>
BinaryTree<K, T>::BinaryTree(std::initializer_list<value_type> const& items)
    : BinaryTree() {
  const value_type* inserted_items[items.size()];
  size_t i = 0;
  try {
    for (const_reference item : items) {
      if (insert(item).second) {
        inserted_items[i] = &item;
        ++i;
      }
    }
  } catch (...) {
    for (; i > 0; --i) {
      erase(find(inserted_items[i]->first));
    }
    std::cerr << "container creation error.\n";
  }
}

template <typename K, typename T>
BinaryTree<K, T>::BinaryTree(const BinaryTree<K, T>& b_tree) : BinaryTree() {
  merge(b_tree);
}

template <typename K, typename T>
BinaryTree<K, T>::BinaryTree(BinaryTree<K, T>&& b_tree) {
  *this = b_tree;
}

template <typename K, typename T>
BinaryTree<K, T>::~BinaryTree() {
  clear();
  delete nil_;
}

template <typename K, typename T>
BinaryTree<K, T>& BinaryTree<K, T>::operator=(BinaryTree<K, T>&& b_tree) {
  std::swap(root_, b_tree.root_);
  std::swap(nil_, b_tree.nil_);
  std::swap(min_, b_tree.min_);
  std::swap(max_, b_tree.max_);
  std::swap(size_, b_tree.size_);
  // b_tree.~BinaryTree(); // to check if nil node should remain
  return this;
}

// BinaryTree iterators

template <typename K, typename T>
typename BinaryTree<K, T>::iterator BinaryTree<K, T>::begin() {
  return iterator(min_, nil_);
}

template <typename K, typename T>
typename BinaryTree<K, T>::const_iterator BinaryTree<K, T>::cbegin() const {
  return const_iterator(min_, nil_);
}

template <typename K, typename T>
typename BinaryTree<K, T>::iterator BinaryTree<K, T>::end() {
  return iterator(nil_, nil_);
}

template <typename K, typename T>
typename BinaryTree<K, T>::const_iterator BinaryTree<K, T>::cend() const {
  return const_iterator(nil_, nil_);
}

// BinaryTree capacity
template <typename K, typename T>
bool BinaryTree<K, T>::empty() {
  return nil_ == root_;
}

template <typename K, typename T>
typename BinaryTree<K, T>::size_type BinaryTree<K, T>::size() const {
  return size_;
}

template <typename K, typename T>
typename BinaryTree<K, T>::size_type BinaryTree<K, T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(BTNode<K, T>);
}

// BinaryTree modifiers
template <typename K, typename T>
void BinaryTree<K, T>::clear() {
  iterator root(root_, nil_);
  clear_branch(root);
}

template <typename K, typename T>
std::pair<typename BinaryTree<K, T>::iterator, bool> BinaryTree<K, T>::insert(
    const_reference value) {
  return insert(value.first, value.second);
}

template <typename K, typename T>
std::pair<typename BinaryTree<K, T>::iterator, bool> BinaryTree<K, T>::insert(
    const key_type& key, const mapped_type& obj) {
  iterator it(nil_, nil_);
  if (!find_insert_place(key, it)) {
    return std::make_pair(it, false);
  }
  try {
    BTNode<K, T>* node = new BTNode<K, T>('r', key, obj, it.current_, nil_);
    node_insertion(it, node);
    insert_balance(iterator(node, nil_));
    ++size_;
  } catch (const std::bad_alloc& ba_error) {
    std::cerr << ba_error.what() << std::endl;
    throw;
  }
  return std::make_pair(it, true);
}

template <typename K, typename T>
void BinaryTree<K, T>::erase(iterator pos) {
  if (pos.current_ != nil_) {
    erase_balance(pos);
    if (pos.current_ == min_) {
      min_ = min_->parent_;
    } else if (pos.current_ == max_) {
      max_ = min_->parent_;
    }
    clear_branch(pos);
    root_->color_ = 'b';
    --size_;
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::swap(BinaryTree<K, T>& other) {
  std::swap(root_, other.root_);
  std::swap(nil_, other.nil_);
  std::swap(min_, other.min_);
  std::swap(size_, other.size_);
}

template <typename K, typename T>
void BinaryTree<K, T>::merge(const BinaryTree<K, T>& other) {
  const_iterator oth_it = other.cbegin();
  value_type* inserted_items[other.size()];
  size_t i = 0;
  try {
    for (; oth_it.current_ != oth_it.nil_; ++oth_it) {
      if (insert(*oth_it).second) {
        inserted_items[i] = &oth_it.current_->obj_;
        ++i;
      }
    }
  } catch (...) {
    for (; i > 0; --i) {
      erase(find(inserted_items[i]->first));
    }
    std::cerr << "container items insertion error.\n";
  }
}

// BinaryTree lookup
template <typename K, typename T>
typename BinaryTree<K, T>::iterator BinaryTree<K, T>::find(
    const key_type& key) {
  iterator it(root_, nil_);
  while (it.current_ != nil_) {
    if (key > (*it).first) {
      it.current_ = it.current_->right_;
    } else if (key < (*it).first) {
      it.current_ = it.current_->left_;
    } else {
      break;
    }
  }
  return it;
}

template <typename K, typename T>
bool BinaryTree<K, T>::contains(const key_type& key) {
  return find(key).current_ != nil_;
}

template <typename K, typename T>
bool BinaryTree<K, T>::find_insert_place(const key_type& key, iterator& it) {
  iterator successor(root_, nil_);
  while (successor.current_ != nil_) {
    it = successor;
    if (key > (*successor).first) {
      successor = successor.right_son();
    } else if (key < (*successor).first) {
      successor = successor.left_son();
    } else {
      return false;
    }
  }
  return true;
}

template <typename K, typename T>
void BinaryTree<K, T>::node_insertion(iterator it, BTNode<K, T>* node) {
  if (root_ == nil_) {
    root_ = min_ = max_ = node;
  } else if (node->obj_.first > (*it).first) {
    it.current_->right_ = node;
    if (it.current_ == max_) {
      max_ = node;
      nil_->left_ = nil_->right_ = max_;
    }
  } else {
    it.current_->left_ = node;
    if (it.current_ == min_) {
      min_ = node;
    }
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::clear_branch(iterator pos) {
  if (pos.current_ == pos.nil_) {
    return;
  }
  if (pos.current_->left_ != pos.nil_) {
    clear_branch(pos.left_son());
  }
  if (pos.current_->right_ != pos.nil_) {
    clear_branch(pos.right_son());
  }
  if (pos.current_ == root_) {
    nil_->left_ = nil_->right_ = nil_;
    root_ = min_ = max_ = nil_;
  } else if (pos.is_left()) {
    pos.current_->parent_->left_ = nil_;
  } else {
    pos.current_->parent_->right_ = nil_;
  }
  delete pos.current_;
}

template <typename K, typename T>
void BinaryTree<K, T>::insert_balance(iterator pos) {
  if (pos.current_->parent_ == nil_) {
    pos.current_->color_ = 'b';
  } else if (pos.current_->parent_->color_ == 'r') {
    if (pos.uncle().current_->color_ == 'r') {
      insert_case_1(pos);
    } else {
      insert_case_2(pos);
    }
    root_->color_ = 'b';
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::insert_case_1(iterator pos) {  // parent red, uncle red
  pos.parent().current_->color_ = 'b';
  pos.uncle().current_->color_ = 'b';
  pos.grandpa().current_->color_ = 'r';
  insert_balance(pos.grandpa());
  root_->color_ = 'b';
}

template <typename K, typename T>
void BinaryTree<K, T>::insert_case_2(iterator pos) {  // parent red, uncle black
  if (pos.parent().is_left()) {
    if (pos.is_right()) {
      left_rotate(pos.parent());
      insert_case_2(pos.left_son());
      pos.current_->right_->color_ = 'r';
      pos.current_->color_ = 'b';
    } else {
      right_rotate(pos.grandpa());
      pos.current_->parent_->right_->color_ = 'r';
      pos.current_->parent_->color_ = 'b';
    }
  } else {
    if (pos.is_left()) {
      right_rotate(pos.parent());
      insert_case_2(pos.right_son());
      pos.current_->left_->color_ = 'r';
      pos.current_->color_ = 'b';
    } else {
      left_rotate(pos.grandpa());
      pos.current_->parent_->left_->color_ = 'r';
      pos.current_->parent_->color_ = 'b';
    }
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_balance(iterator& pos) {
  if (pos.current_->left_ == nil_ && pos.current_->right_ == nil_) {
    erase_case_1(pos);
  } else if (pos.current_->left_ == nil_ || pos.current_->right_ == nil_) {
    erase_case_2(pos);
  } else {
    erase_case_3(pos);
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::right_rotate(iterator pos) {
  if (pos.current_ == root_) {
    root_ = pos.current_->left_;
  } else if (pos.is_left()) {
    pos.current_->parent_->left_ = pos.current_->left_;
  } else {
    pos.current_->parent_->right_ = pos.current_->left_;
  }
  pos.current_->left_->parent_ = pos.current_->parent_;
  pos.current_->parent_ = pos.current_->left_;
  pos.current_->left_ = pos.current_->left_->right_;
  pos.current_->parent_->right_->parent_ = pos.current_;
  pos.current_->parent_->right_ = pos.current_;
}

template <typename K, typename T>
void BinaryTree<K, T>::left_rotate(iterator pos) {
  if (pos.current_ == root_) {
    root_ = pos.current_->right_;
  } else if (pos.is_left()) {
    pos.current_->parent_->left_ = pos.current_->right_;
  } else {
    pos.current_->parent_->right_ = pos.current_->right_;
  }
  pos.current_->right_->parent_ = pos.current_->parent_;
  pos.current_->parent_ = pos.current_->right_;
  pos.current_->right_ = pos.current_->right_->left_;
  pos.current_->parent_->left_->parent_ = pos.current_;
  pos.current_->parent_->left_ = pos.current_;
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_case_1(iterator pos) {  // no sons
  if (pos.current_->color_ == 'b') {
    if (pos.current_->parent_->color_ == 'r') {
      erase_case_1_a(pos);
    } else if (pos.sibling().current_->color_ == 'r') {
      erase_case_1_b(pos);
    } else {
      erase_case_1_c(pos);
    }
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_case_1_a(iterator pos) {  // no sons, parent is red
  if (pos.has_red_nephew()) {
    red_nephew_rotations(pos);
  } else {
    pos.parent().current_->change_color();
    pos.sibling().current_->change_color();
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_case_1_b(
    iterator pos) {  // no sons, parent is black, sibling red
  iterator sibling(pos.sibling());
  if (pos.is_right()) {
    if (sibling.left_son().has_red_nephew()) {
      left_rotate(sibling);
      right_rotate(pos.parent());
      pos.uncle().current_->right_->color_ = 'b';
    } else {
      right_rotate(pos.parent());
      pos.grandpa().current_->color_ = 'b';
      pos.sibling().current_->color_ = 'r';
    }
  } else {
    if (sibling.right_son().has_red_nephew()) {
      right_rotate(sibling);
      left_rotate(pos.parent());
      pos.uncle().current_->left_->color_ = 'b';
    } else {
      left_rotate(pos.parent());
      pos.grandpa().current_->color_ = 'b';
      pos.sibling().current_->color_ = 'r';
    }
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_case_1_c(
    iterator pos) {  // no sons, parent is black, sibling black
  if (pos.has_red_nephew()) {
    red_nephew_rotations(pos);
  } else {
    pos.sibling().current_->color_ = 'r';
    iterator parent(pos.parent());
    erase_case_1(parent);
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_case_2(iterator pos) {  // 1 son
  if (pos.current_->left_ == nil_) {
    left_rotate(pos);
  } else {
    right_rotate(pos);
  }
  pos.current_->parent_->color_ = 'b';
  move_root(pos.current_, pos.current_->parent_);
}

template <typename K, typename T>
void BinaryTree<K, T>::erase_case_3(iterator& pos) {  // 2 sons
  iterator prev(pos);
  --prev;
  key_type* tmp = const_cast<key_type*>(&pos.current_->obj_.first);
  *tmp = prev.current_->obj_.first;
  pos.current_->obj_.second = prev.current_->obj_.second;
  erase_balance(prev);
  pos.current_ = prev.current_;
}

template <typename K, typename T>
void BinaryTree<K, T>::move_root(BTNode<K, T>* old_root,
                                 BTNode<K, T>* new_root) {
  if (old_root == root_) {
    root_ = new_root;
    new_root->parent_ = nil_;
    new_root->color_ = 'b';
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::red_nephew_rotations(iterator pos) {
  if (pos.is_left()) {
    if (pos.sibling().current_->left_->color_ == 'r') {
      right_rotate(pos.sibling());
    }
    left_rotate(pos.parent());
  } else {
    if (pos.sibling().current_->right_->color_ == 'r') {
      left_rotate(pos.sibling());
    }
    right_rotate(pos.parent());
  }
  pos.grandpa().current_->color_ = pos.current_->parent_->color_;
  pos.current_->parent_->color_ = pos.uncle().current_->color_ = 'b';
}

template <typename K, typename T>
void BinaryTree<K, T>::print_tree() {
  iterator pos(root_, nil_);
  if (pos.current_ != nil_) {
    size_type width = count_width(pos) * 4;
    std::cout << std::endl;
    for (size_type i = 0; i < width * 3 / 4; ++i) {
      std::cout << ' ';
    }
    std::cout << ' ' << pos->first << ' ' << pos.current_->color_ << ' ';
    for (size_type i = 0; i < width; ++i) {
      std::cout << ' ';
    }
    std::cout << std::endl;
    for (size_type i = 0; i < 10; ++i) {
      width = width / 2;
      print_layer(width, i);
    }
    std::cout << std::endl;
  }
}

template <typename K, typename T>
void BinaryTree<K, T>::print_layer(int left_offset, size_type depth_to_print) {
  std::cout << std::endl;
  for (int i = 0; i < left_offset; ++i) {
    std::cout << ' ';
  }
  for (auto it = begin(); it != end(); ++it) {
    if (depth(it) == depth_to_print) {
      print_childs(it, left_offset);
    }
  }
  std::cout << std::endl;
}

template <typename K, typename T>
void BinaryTree<K, T>::print_childs(iterator pos, int left_offset) {
  if (pos.current_->left_ != nil_) {
    std::cout << ' ' << pos.left_son()->first << ' '
              << pos.left_son().current_->color_ << ' ';
  } else {
    std::cout << "  _  ";
  }
  for (int i = 0; i < left_offset + 2; ++i) {
    std::cout << ' ';
  }
  if (pos.current_->right_ != nil_) {
    std::cout << ' ' << pos.right_son()->first << ' '
              << pos.right_son().current_->color_ << ' ';
  } else {
    std::cout << "  _  ";
  }
  for (int i = 0; i < left_offset; ++i) {
    std::cout << ' ';
  }
}

template <typename K, typename T>
typename BinaryTree<K, T>::size_type BinaryTree<K, T>::count_width(
    iterator pos) {
  size_type width = 0;
  if (pos.current_->left_ == nil_) {
    ++width;
  } else {
    width += count_width(pos.left_son());
  }
  if (pos.current_->right_ == nil_) {
    ++width;
  } else {
    width += count_width(pos.right_son());
  }
  return width;
}

template <typename K, typename T>
typename BinaryTree<K, T>::size_type BinaryTree<K, T>::depth(iterator pos) {
  size_type depth = 0;
  while (pos.current_->parent_ != nil_) {
    pos.current_ = pos.current_->parent_;
    ++depth;
  }
  return depth;
}

}  // namespace s21