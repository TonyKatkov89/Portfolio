#ifndef CPP2_S21_CONTAINERS_SRC_S21_ARRAY_TPP_
#define CPP2_S21_CONTAINERS_SRC_S21_ARRAY_TPP_

namespace s21 {

template <typename T, std::size_t Size>
array<T, Size>::array() {}

template <typename T, std::size_t Size>
array<T, Size>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), elements);
}

template <typename T, std::size_t Size>
array<T, Size>::array(const array &other) {
  for (size_t i = 0; i < Size; ++i) {
    elements[i] = other.elements[i];
  }
}

template <typename T, std::size_t Size>
array<T, Size>::array(array &&other) {
  for (size_t i = 0; i < Size; ++i) {
    elements[i] = std::move(other.elements[i]);
  }
}

template <typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::begin() {
  return elements;
}

template <typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::end() {
  return elements + capacity;
}

template <typename T, std::size_t Size>
typename array<T, Size>::iterator array<T, Size>::data() {
  return begin();
}

template <typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::at(size_type pos) {
  if (pos >= Size) throw std::out_of_range("Index out of range");
  return elements[pos];
}

template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::front() {
  const_reference result = elements[0];
  return result;
}

template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::back() {
  const_reference result = elements[Size - 1];
  return result;
}

template <typename T, std::size_t Size>
bool array<T, Size>::empty() {
  return Size == 0;
  //    return !capacity;
}

template <typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::size() {
  return capacity;
}

template <typename T, std::size_t Size>
typename array<T, Size>::size_type array<T, Size>::max_size() {
  return capacity;
}

template <typename T, std::size_t Size>
void array<T, Size>::swap(array &other) {
  //    T tmp;
  for (size_t i = 0; i < capacity; ++i) {
    //        tmp = elements[i];
    //        elements[i] = other.elements[i];
    //        other.elements[i] = tmp;
    std::swap(elements[i], other.elements[i]);
  }
}

template <typename T, std::size_t Size>
void array<T, Size>::fill(const_reference value) {
  for (size_t i = 0; i < capacity; ++i) {
    elements[i] = value;
  }
}

template <typename T, std::size_t Size>
typename array<T, Size>::array &array<T, Size>::operator=(const array &other) {
  for (size_t i = 0; i < capacity; ++i) {
    elements[i] = other.elements[i];
  }

  return *this;
}

template <typename T, std::size_t Size>
typename array<T, Size>::array &array<T, Size>::operator=(array &&other) {
  for (size_t i = 0; i < capacity; ++i) {
    elements[i] = std::move(other.elements[i]);
  }

  return *this;
}

template <typename T, std::size_t Size>
typename array<T, Size>::reference array<T, Size>::operator[](size_type pos) {
  if (pos >= Size) throw std::out_of_range("Index out of range");
  return elements[pos];
}

template <typename T, std::size_t Size>
typename array<T, Size>::const_reference array<T, Size>::operator[](
    size_type pos) const {
  if (pos >= Size) throw std::out_of_range("Index out of range");
  return elements[pos];
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_S21_ARRAY_TPP_
