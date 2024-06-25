/*
Title:
Sequence Order

Description:
You have n integers (n ≤ 100) that are already sorted in ascending order. 
Now, you are given another integer x. Please insert this integer into the sequence 
and ensure that the new sequence remains in ascending order.

Input:
The input data contains multiple test cases. 
Each test case consists of two lines: 
the first line contains the numbers n and m, 
and the second line contains a sequence of n numbers that are already sorted. 
The input ends when both n and m are zero, and this line should not be processed.

Output:
For each test case, output the sequence after the new element has been inserted.

Sample Input:
	3 3
	1 2 4
	0 0


Sample Output:
	1 2 3 4

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
    int n, x;
    while( cin >> n >> x ){
        if(!n && !x){
            break;
        }
        LinkedList list;
        while(n--){
            eleType value;
            cin >> value;
            list.append(value);
        }
        list.ascInsert(x);
        list.print();
    }

    return 0;
}