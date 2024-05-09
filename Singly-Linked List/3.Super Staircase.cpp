/*
Title:
Super Staircase

Description:
When you start at the first level, 
if you can only go up one or two levels at a time, how many ways do you have to go up to the M level?

Input:
The input data first contains an integer N, representing the number of test instances, 
followed by N rows of data, each containing an integer M (1<=M<=40), representing the number of stairs.

Output:
For each test instance, output the number of different moves


Sample input:
	2
	2
	3

Sample output:
    1
	2
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
    void append(eleType value);
    void ascInsert(eleType value);
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

void LinkedList::append(eleType value){
    insert(size, value);
}

void LinkedList::ascInsert(eleType value){
    if(size == 0){
        insert(0, value);
        return;
    }

    for(int i = 0; i < size; i++){
        if(value <= get(i)->data){
            insert(i, value);
            return;
        }
    }

    // If the value is greater than all the elements
    insert(size, value); 

}

int main() {
    LinkedList list;
    
    // Fibonacci
    list.insert(0,1);
    list.insert(1,1);
    list.insert(2,1);
    for(int i=3; i <= 40; i++){
        ListNode* a = list.get(i-1);
        ListNode* b = list.get(i-2);
        // Get the sum of the 2 numbers before current index
        list.insert(i, a->data + b->data);
    }
    list.print();
    
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << list.get(x)->data << endl;
    }
    return 0;
}