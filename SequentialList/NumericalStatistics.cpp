// Question: Numerical Statistics
// Problem Description: Count the number of negative, zero, and positive numbers among the given n numbers.
// Input: The input data consists of multiple sets, each set occupies one line. The first number in each line is an integer n (n < 100), indicating the number of values to be counted. This is followed by n real numbers. If n = 0, it indicates the end of input, and that line should not be processed.
// Output： For each set of input data, output one line with three numbers a, b, c, representing the counts of negative numbers, zero, and positive numbers respectively.   

#include <iostream>
using namespace std;

// Define the type of elements stored in the list
#define eleType double

// Define a structure for a sequential list
struct SequentialList {
    eleType *elements;  // Pointer to the array of elements
    int size;           // Current size of the list
    int capacity;       // Maximum capacity of the list
};

// Function to initialize the list with a given capacity
void initializeList(SequentialList *list, int capacity){
    list->elements = new eleType[capacity]; // Allocate memory for the elements array
    list->size = 0;                         // Initialize the size to zero
    list->capacity = capacity;              // Set the capacity of the list
}

// Function to destroy the list and deallocate memory
void destroyList(SequentialList *list){
    delete [] list -> elements; // Deallocate memory for the elements array
}

// Function to get the current size of the list
int size(SequentialList *list){
    return list->size;
}

// Function to check if the list is empty
bool isEmpty(SequentialList *list) {
    return list->size == 0;
}

// Function to insert an element at a specified index
void insert(SequentialList *list, int index, eleType element){
    // Check for invalid index
    if(index < 0 || index > list->size){
        throw std::invalid_argument("Invalid Index");
    }
    // Check if the list is full, resize if necessary
    if(list->size == list->capacity){
        int newCapacity = list->capacity * 2;
        eleType *newElements = new eleType[newCapacity];
        for(int i = 0; i < list->size; ++i) {
            newElements[i] = list->elements[i];
        }
        delete [] list->elements;
        list->elements = newElements;
        list->capacity = newCapacity;
    }
    // Shift elements to make space for the new element
    for(int i = list->size; i > index; i--){
        list->elements[i] = list->elements[i-1];
    }
    // Insert the new element at the specified index
    list->elements[index] = element;
    list->size++; // Increment the size of the list
}

// Function to delete an element at a specified index
void deleteElement(SequentialList *list, int index){
    // Check for invalid index
    if(index < 0 || index >= list->size){
        throw std::invalid_argument("Invalid Index");
    }
    // Shift elements to overwrite the deleted element
    for(int i=index; i < list->size -1; ++i){
          list->elements[i] = list->elements[i+1];
    }
    list->size--; // Decrement the size of the list
}

// Function to find the index of a specified element
int findElement(SequentialList *list, eleType element){
    // Search for the element in the list
    for(int i=0; i < list->size; i++){
        if(list->elements[i] == element){
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to get the element at a specified index
eleType getElement(SequentialList *list, int index){
    // Check for invalid index
    if(index < 0 || index >= list->size){
        throw std::invalid_argument("Invalid Index");
    }
    return list->elements[index]; // Return the element at the specified index
}

// Function to update the element at a specified index
void updateElement(SequentialList *list, int index, eleType value){
    // Check for invalid index
    if(index < 0 || index >= list->size){
        throw std::invalid_argument("Invalid Index");
    }
    list->elements[index] = value; // Update the element at the specified index
}

int main(){
    int n;
    while(cin >> n && n){
        SequentialList s; 
        initializeList( &s, 1);
        
        for(int i=0; i < n; i++){
            eleType x;
            cin >> x;
            insert( &s, i, x);
        }
        
        int pcnt = 0, zcnt = 0, ncnt = 0;
        for(int i = 0; i<size(&s); i++){
            eleType ele = getElement(&s, i);
            if(ele > 1e-8){
                pcnt++;
            }else if( ele < -1e-8){
                ncnt++;
            }else{
                zcnt++;
            }
        }
        
        cout << ncnt << ' ' << zcnt << ' ' << pcnt << endl;
        
    }
    return 0;
}


