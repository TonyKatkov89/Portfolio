#ifndef CPP2_S21_CONTAINERS_1_S21_MAP_H_
#define CPP2_S21_CONTAINERS_1_S21_MAP_H_

#include "../s21_btree/s21_btree.h"

namespace s21 {

template <typename K, typename T>
class map : public BinaryTree<K, T> {
 public:
  // map member type
  using key_type = K;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = BTIterator<K, T>;
  using const_iterator = BTConstIterator<K, T>;
  using size_type = size_t;

  // map constructors and destructor

  map() : BinaryTree<K, T>(){};

  map(std::initializer_list<value_type> const& items)
      : BinaryTree<K, T>(items){};

  map(const map& m) : map() { this->merge(m); }

  map(map&& m) : map() {
    std::swap(this->root_, m.root_);
    std::swap(this->nil_, m.nil_);
    std::swap(this->min_, m.min_);
    std::swap(this->max_, m.max_);
    std::swap(this->size_, m.size_);
  }

  ~map() {}

  map<K, T>& operator=(map<K, T>&& m) {
    std::swap(this->root_, m.root_);
    std::swap(this->nil_, m.nil_);
    std::swap(this->min_, m.min_);
    std::swap(this->max_, m.max_);
    std::swap(this->size_, m.size_);
    return this;
  }
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_S21_MAP_H_