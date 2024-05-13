#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int size;
    int capacity;
    void resize();

public:
    Stack() : data(new T[capacity]), size(0), capacity(10) {}
    ~Stack();
    void push(T value);
    T pop();
    T top() const;
    int getSize() const;
};

template <typename T>
void Stack<T>::resize() {
    T* temp = new T[capacity * 2];
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}

template <typename T>
void Stack<T>::push(T value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (size == 0) {
        throw runtime_error("Stack is empty");
    }
    return data[--size];
}

template <typename T>
T Stack<T>::top() const {
    if (size == 0) {
        throw runtime_error("Stack is empty");
    }
    return data[size - 1];
}

template <typename T>
int Stack<T>::getSize() const {
    return size;
}

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl;
    cout << stack.top() << endl;
    cout << stack.getSize() << endl;
    return 0;
}