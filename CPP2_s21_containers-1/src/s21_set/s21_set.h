#ifndef CPP2_S21_CONTAINERS_1_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_S21_SET_H_

#include "../s21_btree/s21_btree.h"
#include "s21_set_iterator.h"

namespace s21 {

template <typename K>
class set : public BinaryTree<K, K> {
 public:
  // set member type
  using T = K;
  using key_type = K;
  using mapped_type = K;
  using value_type = K;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = SetIterator<K, T>;
  using const_iterator = SetIterator<K, T>;
  using size_type = size_t;

  // set constructors and destructor
  set() : BinaryTree<K, T>(){};

  set(std::initializer_list<value_type> const& items) : BinaryTree<K, T>() {
    for (const value_type& item : items) {
      insert(item);
    }
  }

  set(const set& s) : set() { this->merge(s); }

  set(set&& s) : set() {
    std::swap(this->root_, s.root_);
    std::swap(this->nil_, s.nil_);
    std::swap(this->min_, s.min_);
    std::swap(this->max_, s.max_);
    std::swap(this->size_, s.size_);
  }

  ~set() {}

  set<K>& operator=(set<K>&& s) {
    std::swap(this->root_, s.root_);
    std::swap(this->nil_, s.nil_);
    std::swap(this->min_, s.min_);
    std::swap(this->max_, s.max_);
    std::swap(this->size_, s.size_);
    return this;
  }

  // set iterators
  iterator begin() { return iterator(this->min_, this->nil_); }

  const_iterator cbegin() const {
    return const_iterator(this->min_, this->nil_);
  }

  iterator end() { return iterator(this->nil_, this->nil_); }

  const_iterator cend() const { return const_iterator(this->nil_, this->nil_); }

  // set modifiers
  std::pair<iterator, bool> insert(const value_type& value) {
    return insert(value, value);
  }

  // set lookup
  iterator find(const key_type& key) {
    iterator it(this->root_, this->nil_);
    while (it.current_ != this->nil_) {
      if (key > *it) {
        it.current_ = it.current_->right_;
      } else if (key < *it) {
        it.current_ = it.current_->left_;
      } else {
        break;
      }
    }
    return it;
  }

 private:
  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) {
    iterator it(this->nil_, this->nil_);
    if (!this->find_insert_place(key, it)) {
      return std::make_pair(it, false);
    }
    BTNode<K, T>* node =
        new BTNode<K, T>('r', key, obj, it.current_, this->nil_);
    this->node_insertion(it, node);
    this->insert_balance(iterator(node, this->nil_));
    ++this->size_;

    return std::make_pair(it, true);
  }
};

}  // namespace s21

// #include "s21_set.tpp"

#endif  // CPP2_S21_CONTAINERS_1_S21_set_H_