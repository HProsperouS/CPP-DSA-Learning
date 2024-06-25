/*
Title:
A + B for Input-Output Practice (IV)

Description:
Your task is to calculate the sum of some integers

Input:
Input contains multiple test case. Each test case contains a integer N, and then N integers follow in the same line.
A test case starting with 0 terminates the input and test case is not to be processed.

Output:
For each group of integers you should output their sum in one line, 
and with one line of output for each line in input

Sample Input:
	4 1 2 3 4
	5 1 2 3 4 5
	0

Sample Output:
    10
	15
	
*/

#include <iostream>
#include <stdexcept>
using namespace std;

#define eleType int

struct ListNode{
    eleType data;
    ListNode* next;
    ListNode(int x): data(x), next(NULL) {}
};

class LinkedList{
private:
    ListNode* head;
    int size;

public:
    LinkedList(): head(NULL), size(0) {}
    ~LinkedList(); // Destructor
    void insert(int i, eleType value);
    void remove(int i);
    ListNode* find(eleType value);
    ListNode* get(int i);
    void update(int i, eleType value);
    void print();
    eleType sum();
};

LinkedList::~LinkedList(){
    ListNode* curr = head;
    while(curr){
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedList::insert(int i, eleType value){
    if(i < 0 || i > size){
        throw std::out_of_range("Invalid Index");
    };

    ListNode* newNode = new ListNode(value);
    if(i == 0){
        newNode->next = head;
        head = newNode;
    }else{
        ListNode* curr = head;
        for(int j = 0; j < i-1; j++){
            curr = curr->next;
        }
        // Current is the node before the new node
        newNode->next = curr->next;
        curr->next = newNode;
    }
    size++;
}

void LinkedList::remove(int i){
    if(i < 0 || i >= size){
        throw std::out_of_range("Invalid Index");
    };

    ListNode* temp;
    if(i == 0){
        temp = head;
        head = head->next;
    }else{
        ListNode* curr = head;
        for(int j = 0; j < i-1; j++){
            curr = curr->next;
        }
        // Current is the node before the node to be deleted
        temp = curr->next;
        curr->next = temp->next;
    }
    delete temp;
    size--;
}

ListNode* LinkedList::find(eleType value){
    ListNode* curr = head;
    while(curr && curr->data != value){
        curr = curr->next;
    }
    return curr;
}

ListNode* LinkedList::get(int i){
    if(i < 0 || i >= size){
        throw std::out_of_range("Invalid Index");
    };

    ListNode* curr = head;
    for(int j = 0; j < i; j++){
        curr = curr->next;
    }
    return curr;
}

void LinkedList::update(int i, eleType value){
    get(i)->data = value;
}

void LinkedList::print(){
    ListNode* curr = head;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

eleType LinkedList::sum(){
    ListNode* curr = head;
    eleType sum = 0;
    while(curr != NULL){
        sum += curr->data;
        curr = curr->next;
    }
    return sum;
}

int main() {
    int n;
    while( cin>>n ){
        LinkedList list;
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            list.insert(i,x);
        }
        cout << list.sum() << endl;
    }

    return 0;
}