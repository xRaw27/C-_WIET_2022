//
// Created by xraw on 18.05.2022.
//

#ifndef MYSORTING_H
#define MYSORTING_H

#include <algorithm>
#include <vector>
#include <cstring>
#include "myList.h"

template<class T, size_t n>
void mySort(T(&arr)[n]) {
    std::sort(arr, arr + n);
}

template<size_t n, size_t m>
void mySort(char(&arr)[n][m]) {
    std::vector<std::string> strings(n);
    for (size_t i = 0; i < n; ++i) {
        strings[i] = std::string(arr[i]);
    }

    std::sort(strings.begin(), strings.end(), [](const auto &str1, const auto &str2) {
        return lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end(), [](const char &char1, const char &char2) {
            return tolower(char1) < tolower(char2);
        });
    });

    for (size_t i = 0; i < n; ++i) {
        strcpy(arr[i], strings[i].c_str());
    }
}

template<class T>
void mySort(T &arr) {
    std::sort(arr.begin(), arr.end());
}

template<class T>
void mySort(MyList<T> &arr) {
    std::vector<std::unique_ptr<typename MyList<T>::Node>> pointers(arr.size());

    pointers[0] = std::move(arr.head);
    for (size_t i = 1; i < arr.size(); ++i) {
        pointers[i] = std::move(pointers[i - 1]->next);
    }

    std::sort(pointers.begin(), pointers.end(), [](const auto &l, const auto &r) {
        return l->getValue() < r->getValue();
    });

    for (size_t i = arr.size() - 1; i > 0; --i) {
        pointers[i - 1]->next = std::move(pointers[i]);
    }
    arr.head = std::move(pointers[0]);
}

#endif //MYSORTING_H
