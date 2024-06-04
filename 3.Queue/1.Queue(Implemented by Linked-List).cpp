#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue{
private:
    struct Node{
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* front;    // Points to the front of the queue
    Node* rear;     // Points to the rear of the queue
    int size;       // Number of elements in the queue

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {};
    ~Queue();
    void enquque(T val);
    T dequeue();
    T getFront() const;
    int getSize() const;
};

template <typename T>
Queue<T>::~Queue(){
    // Delete all nodes in the queue
    while(front != nullptr){
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}


template <typename T>
void Queue<T>::enquque(T val){
    Node* newNode = new Node(val);
    if(front == nullptr){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename T>
T Queue<T>::dequeue(){
    if(front == nullptr){
        throw runtime_error("Queue is empty");
    }
    Node* temp = front;
    T val = front->data;
    front = front->next;
    delete temp;
    size--;
    return val;
}

template <typename T>
T Queue<T>::getFront() const{
    if(front == nullptr){
        throw runtime_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
int Queue<T>::getSize() const{
    return size;
}

int main(){
    Queue<int> q;
    q.enquque(1);
    q.enquque(2);
    q.enquque(3);
    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Front: " << q.getFront() << endl;
    return 0;
}
