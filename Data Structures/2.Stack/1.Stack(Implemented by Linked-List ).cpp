#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(NULL) {}
    };
    Node* head;
    int size;

public:
    Stack() : head(NULL), size(0) {}
    ~Stack();
    void push(T value);
    T pop();
    T top() const;
    int getSize() const;
};

template <typename T>
Stack<T>::~Stack() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Stack<T>::push(T value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template <typename T>
T Stack<T>::pop() {
    if (size == 0) {
        throw runtime_error("Stack is empty");
    }
    Node* temp = head;
    head = head->next;
    T value = temp->data;
    delete temp;
    size--;
    return value;
}

template <typename T>
T Stack<T>::top() const {
    if (size == 0) {
        throw runtime_error("Stack is empty");
    }
    return head->data;
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
    cout << stack.top() << endl;    // 3
    cout << stack.pop() << endl;    // 3
    cout << stack.top() << endl;    // 2
    cout << stack.pop() << endl;    // 2
    cout << stack.top() << endl;    // 1
    cout << stack.pop() << endl;    // 1
    cout << stack.getSize() << endl;    // 0

    return 0;
}