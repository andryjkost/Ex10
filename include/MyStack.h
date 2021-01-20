// Copyright 13.12.20 KostinAndrej

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack{
private:
    int size;
    int current_size;
    T* stack;

public:
    MyStack() {
        this->size = 0;
        this->current_size = 0;
        this->stack = nullptr;
    }
    explicit MyStack(unsigned target_size) {
        this->size = target_size;
        this->current_size = 0;
        this->stack = new T[this->size];
    }
    MyStack(const MyStack& another_MyStack) {
        this->size = another_MyStack.size;
        this->current_size = another_MyStack.current_size;
        this->stack = new T[this->current_size];
        for (unsigned i = 0; i < this->current_size; i++)
            this->stack[i] = another_MyStack.stack[i];
    }
    ~MyStack() {
        delete[] this->stack;
    }
    T get() const {
        if (this->isEmpty())
            return 0;
        return this->stack[this->current_size-1];
    }
    T pop() {
        if (this->isEmpty())
            return 0;
        return this->stack[--current_size];
    }
    void push(T new_element) {
        if (this->isFull()) {
            return;
        }
        this->stack[this->current_size++] = new_element;
    }
    bool isFull() const {
        return this->current_size == this->size;
    }
    bool isEmpty() const {
        return this->current_size == 0;
    }
};

#endif  // INCLUDE_MYSTACK_H_
