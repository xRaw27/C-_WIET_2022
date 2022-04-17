#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()

#include "vector.h"

Vector::Vector(const Vector& v) : size_{v.size_}, capacity_{v.capacity_}, data_{new Fraction[v.capacity_]} {
    std::copy(v.data_, v.data_ + v.capacity_, data_);
}

Vector::Vector(Vector&& v) noexcept : size_{v.size_}, capacity_{v.capacity_}, data_{v.data_} {
    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
}

void Vector::push_back(Fraction fraction) {
    if (size_ == capacity_) {
        reallocate();
    }
    data_[size_++] = fraction;
}

Fraction& Vector::operator[](std::size_t index) {
    if (index < size_) return data_[index];
    throw std::out_of_range("index out of range");
}

const Fraction& Vector::operator[](std::size_t index) const {
    if (index < size_) return data_[index];
    throw std::out_of_range("index out of range");
}

Vector& Vector::operator=(const Vector& v) {
    if (this == &v) return *this;

    delete[] data_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    data_ = new Fraction[capacity_];
    std::copy(v.data_, v.data_ + v.capacity_, data_);

    return *this;
}

Vector& Vector::operator=(Vector&& v) noexcept {
    if (this == &v) return *this;

    delete[] data_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    data_ = v.data_;

    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;

    return *this;
}

void Vector::reallocate() {
    auto* new_data = new Fraction[++capacity_];
    std::copy(data_, data_ + capacity_ - 1, new_data);

    delete[] data_;
    data_ = new_data;
}

