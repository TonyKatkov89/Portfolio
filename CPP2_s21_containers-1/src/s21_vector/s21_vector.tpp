#ifndef CPP2_S21_CONTAINERS_SRC_S21_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_SRC_S21_VECTOR_TPP_

namespace s21 {

template <typename T>
vector<T>::vector() {}

template <typename T>
vector<T>::vector(size_type n) : data_(new T[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, T());
}

template <typename T>
vector<T>::vector(std::initializer_list<T> const& items)
    : data_(new T[items.size()]), size_(items.size()), capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
vector<T>::vector(const vector& v)
    : data_(new T[v.capacity_]), size_(v.size_), capacity_(v.capacity_) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename T>
vector<T>::vector(vector&& v) {
  size_ = std::exchange(v.size_, 0);
  capacity_ = std::exchange(v.capacity_, 0);
  data_ = std::exchange(v.data_, nullptr);
}

template <typename T>
vector<T>::~vector() {
  delete[] data_;
}

template <typename T>
vector<T>& vector<T>::operator=(vector&& v) {
  if (this != &v) {
    clear();
    new (this) vector(std::move(v));
  }
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (this->size() <= pos) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  if (this->size() <= pos) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
  if (size_ == 0) throw std::out_of_range("Index out of range");
  return data_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  if (size_ == 0) throw std::out_of_range("Index out of range");
  return data_[size_ - 1];
}

template <typename T>
typename vector<T>::pointer vector<T>::data() {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(data_);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(data_ + size_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return const_iterator(data_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return const_iterator(data_ + size_);
}

template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(T);
}

template <typename T>
void vector<T>::reserve(size_type new_capacity) {
  if (new_capacity <= capacity_) return;

  if (new_capacity > max_size())
    throw std::length_error("Reserve capacity can't be larger than max size");

  pointer new_data = new T[new_capacity];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    pointer new_data = new T[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::clear() {
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type index = pos - begin();

  if (index > size_) throw std::out_of_range("Unable to insert");

  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }

  iterator new_pos = begin() + index;

  for (iterator it = end(); it != new_pos; --it) {
    *it = *(it - 1);
  }

  *new_pos = value;
  ++size_;
  return new_pos;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_type position = &(*pos) - this->data_;
  size_type zero = 0;
  if (zero > position || position > this->size_) {
    throw std::out_of_range("Index out ot range");
  }
  for (iterator it = pos; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --size_;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  data_[size_++] = value;
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) {
    --size_;
  }
}

template <typename T>
void vector<T>::swap(vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(iterator pos,
                                                    Args&&... args) {
  auto args_v = std::initializer_list<T>{std::forward<Args>(args)...};

  for (auto& i : args_v) {
    insert(pos, i);
  }

  return pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args&&... args) {
  insert_many(end(), args...);
}

}  // namespace s21
#endif  // CPP2_S21_CONTAINERS_SRC_S21_VECTOR_TPP_
