#ifndef SRC_S21_LIST_S21_LIST_TPP_
#define SRC_S21_LIST_S21_LIST_TPP_

#include "s21_list.h"
namespace s21 {
/*
 ---------------------------------------
|                                       |
|           List Constructors           |
|                                       |
 ---------------------------------------
*/

template <typename T>
list<T>::list() noexcept : size_(0) {
  dummy_node_ = new node();
  dummy_node_->next_ = dummy_node_;
  dummy_node_->prev_ = dummy_node_;
}

template <typename T>
list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type());
  }
}
template <typename T>
list<T>::list(std::initializer_list<T> const& items) : list() {
  for (const auto& item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(const list& l) : list() {
  node* current = l.dummy_node_->next_;
  while (current != l.dummy_node_) {
    push_back(current->value_);
    current = current->next_;
  }
}

template <typename T>
list<T>::list(list&& l) noexcept : list() {
  std::swap(dummy_node_, l.dummy_node_);
  std::swap(size_, l.size_);
}

template <typename T>
list<T>& list<T>::operator=(list&& l) noexcept {
  if (this != &l) {
    clear();
    std::swap(dummy_node_, l.dummy_node_);
    std::swap(size_, l.size_);
  }
  return *this;
}

template <typename T>
list<T>::~list() noexcept {
  clear();
  delete dummy_node_;
}

/*
 ---------------------------------------
|                                       |
|           Front/Back Access           |
|                                       |
 ---------------------------------------
*/
template <typename T>
typename list<T>::const_reference list<T>::front() noexcept {
  return dummy_node_->next_->value_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() noexcept {
  return dummy_node_->prev_->value_;
}

/*
 ---------------------------------------
|                                       |
|             List Iterators            |
|                                       |
 ---------------------------------------
*/

template <typename T>
typename list<T>::iterator list<T>::begin() noexcept {
  return iterator(dummy_node_->next_);
}

template <typename T>
typename list<T>::iterator list<T>::end() noexcept {
  return iterator(dummy_node_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const noexcept {
  return const_iterator(dummy_node_->next_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const noexcept {
  return const_iterator(dummy_node_);
}
/*
 ---------------------------------------
|                                       |
|             List Capacity             |
|                                       |
 ---------------------------------------
*/
template <typename T>
bool list<T>::empty() const noexcept {
  if (dummy_node_->next_ == dummy_node_ && dummy_node_->prev_ == dummy_node_) {
    return true;
  }
  return false;
}

template <typename T>
typename list<T>::size_type list<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(node);
}

/*
 ---------------------------------------
|                                       |
|            List Modifiers             |
|                                       |
 ---------------------------------------
*/
template <typename T>
void list<T>::clear() noexcept {
  while (!empty()) {
    try {
      pop_back();
    } catch (const std::out_of_range& e) {
      std::cerr << e.what() << "\n";
    }
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  iterator new_it;
  if (size_ == 0 || (pos == end())) {
    push_back(value);
    iterator temp_it(dummy_node_->prev_);
    new_it = temp_it;
  } else if (pos == begin()) {
    push_front(value);
    iterator temp_it(dummy_node_->next_);
    new_it = temp_it;
  } else {
    node* new_node = new node(value);
    node* cur_node = pos.current_;
    iterator temp_it(new_node);
    new_it = temp_it;
    new_node->next_ = cur_node;
    new_node->prev_ = cur_node->prev_;
    cur_node->prev_->next_ = new_node;
    cur_node->prev_ = new_node;
    ++size_;
  }
  return new_it;
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (pos.current_ == dummy_node_) {
    return;
  }
  node* temp_node = pos.current_;
  if (temp_node->prev_ != dummy_node_) {
    temp_node->prev_->next_ = temp_node->next_;
  } else {
    dummy_node_->next_ = temp_node->next_;
  }
  if (temp_node->next_ != dummy_node_) {
    temp_node->next_->prev_ = temp_node->prev_;
  } else {
    dummy_node_->prev_ = temp_node->prev_;
  }
  delete temp_node;
  --size_;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  if (size() >= max_size()) {
    throw std::out_of_range("ERROR: List container excceded system limit");
  }
  node* new_node = new node(value);
  if (empty()) {
    DummyLinker(new_node);
  } else {
    dummy_node_->prev_->next_ = new_node;
    new_node->prev_ = dummy_node_->prev_;
    DummyLinker(new_node);
  }
  ++size_;
}

template <typename T>
void list<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("ERROR: pop_back on an empty list");
  }
  iterator it(dummy_node_->prev_);
  erase(it);
}

template <typename T>
void list<T>::push_front(const_reference value) {
  if (size() >= max_size()) {
    throw std::out_of_range("ERROR: List container excceded system limit");
  }
  node* new_node = new node(value);
  if (empty()) {
    DummyLinker(new_node);
  } else {
    dummy_node_->next_->prev_ = new_node;
    new_node->next_ = dummy_node_->next_;
    DummyLinker(new_node);
  }
  ++size_;
}

template <typename T>
void list<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("ERROR: pop_front on an empty list");
  }
  iterator it(dummy_node_->next_);
  erase(it);
}

template <typename T>
void list<T>::swap(list& other) noexcept {
  std::swap(dummy_node_, other.dummy_node_);
  std::swap(size_, other.size_);
}
template <typename T>
void list<T>::merge(list& other) {
  if (this == &other) {
    return;
  }
  if (other.empty()) {
    return;
  }
  iterator it_this = this->begin();
  iterator it_other = other.begin();
  while (it_this != this->end() && it_other != other.end()) {
    if (!(*it_other < *it_this)) {
      ++it_this;
    } else {
      iterator temp_it_this = it_this;
      --temp_it_this;
      node* this_curr_node = it_this.current_;
      node* this_prev_node = temp_it_this.current_;
      node* merge_node = it_other.current_;
      ++it_other;
      this_prev_node->next_ = merge_node;
      this_curr_node->prev_ = merge_node;
      merge_node->RelinkNode(this_prev_node, this_curr_node);
      ++(this->size_);
      --(other.size_);
    }
  }
  if (it_other != other.end()) {
    splice(this->cend(), other);
  }
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  node* other_dummy = (other.end()).current_;
  node* other_tail = other_dummy->prev_;
  node* other_head = other_dummy->next_;
  node* insert_before = pos.current_;
  node* insert_after = pos.current_->prev_;

  other_head->prev_ = insert_after;
  other_tail->next_ = pos.current_;

  insert_after->next_ = other_head;
  insert_before->prev_ = other_tail;

  other_dummy->next_ = other_dummy;
  other_dummy->prev_ = other_dummy;
  this->size_ += other.size_;
  other.size_ = 0;
}

template <typename T>
void list<T>::reverse() noexcept {
  if (!empty()) {
    for (iterator i = begin(); i != end(); --i) {
      std::swap(i.current_->next_, i.current_->prev_);
    }
    std::swap(dummy_node_->next_, dummy_node_->prev_);
  }
}

template <typename T>
void list<T>::unique() {
  if (!empty()) {
    iterator previous = begin();
    iterator i = begin();
    ++i;
    while (i != end()) {
      if (previous.current_->value_ == i.current_->value_) {
        iterator temp = i;
        ++i;
        erase(temp);
      } else {
        previous = i;
        ++i;
      }
    }
  }
}

template <typename T>
void list<T>::sort() {
  iterator it = begin();
  list a;
  list b;
  if (it == end() || it.current_->next_ == dummy_node_) {
    return;
  }
  SplitList(a, b);
  a.sort();
  b.sort();
  a.merge(b);
  *this = std::move(a);
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  list insert_list{args...};
  iterator res(pos.current_);
  if (!insert_list.empty()) {
    splice(pos, insert_list);
  }
  return res;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args&&... args) {
  insert_many(cend(), args...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args&&... args) {
  InsertFront(args...);
}

template <typename T>
void list<T>::DummyLinker(node* new_node) noexcept {
  if (!new_node->prev_) {
    new_node->prev_ = dummy_node_;
    dummy_node_->next_ = new_node;
  }
  if (!new_node->next_) {
    new_node->next_ = dummy_node_;
    dummy_node_->prev_ = new_node;
  }
}

template <typename T>
void list<T>::SplitList(list& a, list& b) noexcept {
  if (!empty()) {
    iterator fast = begin();
    iterator slow = begin();
    ++a.size_;
    ++fast;
    while (fast != end()) {
      ++fast;
      if (fast != end()) {
        ++a.size_;
        ++slow;
        ++fast;
      }
    }
    b.size_ = size_ - a.size_;
    node* a_dummy = a.end().current_;
    node* b_dummy = b.end().current_;

    a_dummy->next_ = begin().current_;
    a_dummy->prev_ = slow.current_;
    b_dummy->next_ = slow.current_->next_;
    b_dummy->prev_ = end().current_->prev_;

    a_dummy->next_->prev_ = a_dummy;
    a_dummy->prev_->next_ = a_dummy;
    b_dummy->next_->prev_ = b_dummy;
    b_dummy->prev_->next_ = b_dummy;

    size_ = 0;
    dummy_node_->next_ = dummy_node_;
    dummy_node_->prev_ = dummy_node_;
  }
}

template <typename T>
void list<T>::InsertFront() {}

template <typename T>
template <typename Arg, typename... Rest>
void list<T>::InsertFront(Arg&& arg, Rest&&... rest) {
  push_front(arg);
  InsertFront(rest...);
}

}  // namespace s21

#endif  // SRC_S21_LIST_S21_LIST_TPP_