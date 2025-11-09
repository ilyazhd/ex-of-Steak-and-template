#ifndef HEADER_H
#define HEADER_H
#include <iostream>


template <typename T>
class Stack
{
private:
    int32_t top;
    const int32_t size;
    T* arr;

public:
    explicit Stack(const int32_t & = 100);
    Stack(const Stack&);              
    Stack(Stack&&) noexcept;          
    Stack& operator=(const Stack&);   
    Stack& operator=(Stack&&) noexcept; 
    void push(const T&);
    void pop();
    T& peek();
    const T& peek() const;
    bool IsEmpty() const;
    bool IsFull() const;
    ~Stack();


    //задача про скобки
    bool IsCorrectCh(char ch) {
        switch (ch)
        {
        case ')': return this->peek() == '(';
        case '}': return this->peek() == '{';
        case ']': return this->peek() == '[';
        default:
            return 0;
            break;
        }
    }
    bool IsRightCh(std::string str) {
        for (size_t i = 0; i < str.size(); ++i)
        {

            switch (str[i])
            {
            case '(':
            case '{':
            case '[':
                this->push(str[i]);
                break;
            case ')':
            case '}':
            case ']':
                if (!IsCorrectCh(str[i]))
                {
                    return 0;
                }
                else
                {
                    this->pop();
                }
                break;
            default:
                break;
            }
        }
        return this->IsEmpty();
    }

    //задача про выгоны
    std::string VagonNormalise(const std::string& str) {
        if (str.empty()) return "";

        std::string newStr;

        newStr += str[0]; // первый символ всегда идЄт в результат

        for (size_t i = 1; i < str.size(); ++i) {
            if (str[i] != newStr.back()) {
                newStr += str[i];   // чередование сохран€етс€
            }
            else {
                this->push(str[i]);    // одинаковые символы Ч в стек
            }
        }

        // в конце добавл€ем остатки из стека
        while (!this->IsEmpty()) {
            newStr += this->peek();
            this->pop();
        }

        return newStr;
    }

};

template <typename T>
Stack<T>::Stack(const int32_t& _size) : size(_size), top(0) {
    if (size <= 1) {
        throw std::invalid_argument("incorrect size!\n");
    }
    arr = new T[size];
}

template <typename T>
Stack<T>::Stack(const Stack& other) : size(other.size), top(other.top) {
    arr = new T[size];
    for (int32_t i = 0; i < top; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Stack<T>::Stack(Stack&& other) noexcept : size(other.size), top(other.top), arr(other.arr) {
    other.arr = nullptr;
    other.top = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        if (size != other.size) {
            throw std::invalid_argument("assignment with different sizes not allowed");
        }
        top = other.top;
        for (int32_t i = 0; i < top; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) noexcept {
    if (this != &other) {
        if (arr) delete[] arr;
        const_cast<int32_t&>(size) = other.size; 
        top = other.top;
        arr = other.arr;
        other.arr = nullptr;
        other.top = 0;
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (IsFull()) {
        throw std::overflow_error("Stack is full!\n");
    }
    arr[top++] = value;
}

template <typename T>
void Stack<T>::pop() {
    if (IsEmpty()) {
        throw std::underflow_error("Stack is empty!\n");
    }
    --top;
}

template <typename T>
T& Stack<T>::peek() {
    if (IsEmpty()) {
        throw std::underflow_error("Stack is empty!\n");
    }
    return arr[top - 1];
}

template <typename T>
const T& Stack<T>::peek() const {
    if (IsEmpty()) {
        throw std::underflow_error("Stack is empty!\n");
    }
    return arr[top - 1];
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return top == 0;
}

template <typename T>
bool Stack<T>::IsFull() const {
    return top == size;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

#endif HEADER_H

//задача на скобки {(})[})
//задачка на вагоны #pragma once


