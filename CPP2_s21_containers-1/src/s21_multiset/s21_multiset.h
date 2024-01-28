#ifndef CPP2_S21_CONTAINERS_1_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_1_S21_MULTISET_H_

#include "../s21_set/s21_set.h"

namespace s21 {

template <typename K>
class multiset : public set<K> {
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
  multiset() : set<K>(){};

  multiset(std::initializer_list<value_type> const& items) : set<K>() {
    for (const value_type& item : items) {
      this->insert(item);
    }
  }

  multiset(const multiset& ms) : multiset() { this->merge(ms); }

  multiset(multiset&& ms) : multiset() {
    std::swap(this->root_, ms.root_);
    std::swap(this->nil_, ms.nil_);
    std::swap(this->min_, ms.min_);
    std::swap(this->max_, ms.max_);
    std::swap(this->size_, ms.size_);
  }

  ~multiset() {}

  multiset<K>& operator=(multiset<K>&& ms) {
    std::swap(this->root_, ms.root_);
    std::swap(this->nil_, ms.nil_);
    std::swap(this->min_, ms.min_);
    std::swap(this->max_, ms.max_);
    std::swap(this->size_, ms.size_);
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

  void merge(const multiset<K>& other) {
    const_iterator oth_it = other.cbegin();
    for (; oth_it.current_ != oth_it.nil_; ++oth_it) {
      insert(*oth_it);
    }
  }

  // set lookup

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

  bool find_insert_place(const key_type& key,
                         typename BinaryTree<K, K>::iterator& it) {
    typename BinaryTree<K, T>::iterator successor(this->root_, this->nil_);
    while (successor.current_ != this->nil_) {
      it = successor;
      if (key > (*successor).first) {
        successor = successor.right_son();
      } else if (key <= (*successor).first) {
        successor = successor.left_son();
      }
    }
    return true;
  }
};

}  // namespace s21

// #include "s21_multiset.tpp"

#endif  // CPP2_S21_CONTAINERS_1_S21_MULTI_H_