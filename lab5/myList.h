//
// Created by xraw on 16.05.2022.
//

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <memory>

template<class T>
class MyList {

public:
    typedef T value_type;

    class Node;
    class Iterator;
    class IteratorConst;

    std::unique_ptr <MyList::Node> head;

    MyList() : head{nullptr}, size_{0} {}

    void push_front(T new_value);
    T pop_front();
    void remove(T element);

    [[nodiscard]] T front() const;
    [[nodiscard]] size_t size() const;

    Iterator begin() { return Iterator(head.get()); }
    IteratorConst begin() const { return IteratorConst(head.get()); }
    Iterator end() { return Iterator(nullptr); }
    IteratorConst end() const { return IteratorConst(nullptr); }

private:
    size_t size_;

};


template<class T>
class MyList<T>::Node {

public:
    std::unique_ptr <Node> next;

    explicit Node(T value) : next{nullptr}, value(value) {}
    T const & getValue() const { return value; }

private:
    T value;

    friend class MyList<T>;
};


template<class T>
class MyList<T>::Iterator {

public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::ptrdiff_t difference_type;

    explicit Iterator(Node *p) : current{p} {}

    bool operator!=(const Iterator &other) const {
        return current != other.current;
    }

    T& operator*() {
        return current->value;
    }

    Iterator &operator++() {
        if (current->next == nullptr) {
            current = nullptr;
        } else {
            current = current->next.get();
        }
        return *this;
    }

private:
    Node *current;

};


template<class T>
class MyList<T>::IteratorConst {

public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::ptrdiff_t difference_type;

    explicit IteratorConst(const Node *p) : current{p} {}

    bool operator!=(const IteratorConst &other) const {
        return current != other.current;
    }

    T const & operator*() {
        return current->value;
    }

    IteratorConst const &operator++() {
        if (current->next == nullptr) {
            current = nullptr;
        } else {
            current = current->next.get();
        }
        return *this;
    }

private:
    const Node *current;

};


template<class T>
void MyList<T>::push_front(T new_value) {
    auto new_node = std::make_unique<Node>(new_value);
    new_node->next = std::move(head);
    head = std::move(new_node);
    ++size_;
}

template<class T>
T MyList<T>::pop_front() {
    if (head == nullptr) {
        throw std::out_of_range("Cannot pop from empty list");
    }
    T temp = head->value;
    head = std::move(head->next);
    --size_;
    return temp;
}

template<class T>
void MyList<T>::remove(T element) {

    while (head != nullptr && head->value == element) {
        head = std::move(head->next);
        --size_;
    }

    if (head == nullptr || head->next == nullptr) return;

    Node *prev = head.get();
    Node *curr = head->next.get();
    while (curr != nullptr) {
        if (curr->value == element) {
            prev->next = std::move(curr->next);
            --size_;
            curr = prev->next.get();
        }
        else {
            prev = curr;
            curr = curr->next.get();
        }
    }
}

template<class T>
T MyList<T>::front() const {
    if (head == nullptr) {
        throw std::out_of_range("Empty list");
    }
    return head->value;
}

template<class T>
size_t MyList<T>::size() const {
    return size_;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const MyList<T> &list) {
    for (auto elem : list) {
        os << elem << " ";
    }
    os << "\n";

    return os;
}


#endif //MYLIST_H
