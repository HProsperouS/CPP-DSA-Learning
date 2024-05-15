#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue{
private:
    T* data;        // Points to a dynamic array of queue storage elements
    int front;      // Index of the queue header
    int rear;       // Index at the end of the queue (where the next element is inserted)
    int capacity;   // Queue capacity
    void resize();  // Private function to resize the queue

public:
    Queue() : data(new T[10]) , front(0), rear(0), capacity(10) {};
    ~Queue();
    void enquque(T val);
    T dequeue();
    T getFront() const;
    int getSize() const;
};


template <typename T>
Queue<T>::~Queue(){
    delete[] data;
}

template <typename T>
void Queue<T>::resize(){
    T* newData = new T[capacity * 2];
    for(int i = 0; i < rear; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity *= 2;
}

template <typename T>
void Queue<T>::enquque(T val){
    if(rear == capacity){
        resize();
    }
    data[rear++] = val;
}

template <typename T>
T Queue<T>::dequeue(){
    if(front == rear){
        throw runtime_error("Queue is empty");
    }
    return data[front++];
}

template <typename T>
T Queue<T>::getFront() const{
    if(front == rear){
        throw runtime_error("Queue is empty");
    }
    return data[front];
}

int main(){
    Queue<int> q;
    q.enquque(1);
    q.enquque(2);
    q.enquque(3);
    cout << q.getFront() << endl;
    cout << q.dequeue() << endl;
    cout << q.getFront() << endl;
    cout << q.dequeue() << endl;
    cout << q.getFront() << endl;
    cout << q.dequeue() << endl;

    return 0;
}