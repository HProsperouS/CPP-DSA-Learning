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

int main(){
    LinkedList list;

    // Testing Insert
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);
    list.insert(4, 50);
    list.insert(5, 60);
    list.print();

    // Testing Remove
    list.remove(3);
    list.print();

    // Testing Find
    ListNode* node = list.find(20);
    cout << node->data << endl;

    // Testing Get
    ListNode* node2 = list.get(2);
    cout << node2->data << endl;

    // Testing Update
    list.update(2, 100);
    list.print();

    return 0;
}
