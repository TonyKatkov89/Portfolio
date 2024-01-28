#include "s21_bt_node.h"

namespace s21 {

template <typename K, typename T>
BTNode<K, T>::BTNode(char color, BTNode* parent, BTNode* nil) {
  color_ = color;
  parent_ = parent;
  left_ = right_ = nil;
}

template <typename K, typename T>
BTNode<K, T>::BTNode(char color, const key_type& key, const mapped_type& value,
                     BTNode* parent, BTNode* nil)
    : obj_({key, value}) {
  color_ = color;
  parent_ = parent;
  left_ = right_ = nil;
}

template <typename K, typename T>
BTNode<K, T>::BTNode(char color, const value_type& obj, BTNode* parent,
                     BTNode* nil)
    : obj_({obj.first, obj.second}) {
  color_ = color;
  parent_ = parent;
  left_ = right_ = nil;
}

template <typename K, typename T>
BTNode<K, T>::~BTNode() {}

template <typename K, typename T>
bool BTNode<K, T>::operator==(const BTNode<K, T>& other) {
  return &this == &other;
}

template <typename K, typename T>
bool BTNode<K, T>::operator!=(const BTNode<K, T>& other) {
  return &this != &other;
}

template <typename K, typename T>
void BTNode<K, T>::change_color() {
  color_ = color_ == 'r' ? 'b' : 'r';
}

}  // namespace s21