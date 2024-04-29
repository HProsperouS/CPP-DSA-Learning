// Question: Youth Singer Grand Prix
// Problem Description: In the Youth Singer Grand Prix, the judging panel scores the contestants. The scoring for the contestants involves removing the highest and lowest scores, and then calculating the average score. Please write a program to output the score of a certain contestant.
// Input: The input data consists of multiple sets, each set occupying one line. The first number on each line is n (2 < n <= 100), representing the number of judges, followed by the scores of n judges.
// Output： For each set of input data, output the contestant's score, rounded to 2 decimal places, with each output occupying one line.  

/* 
    Sample Input: 
    3 99 98 97
    4 100 99 98 97
    
    Sample Output:
    98.00
    98.50
*/

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
    while(cin >> n){
        SequentialList s; 
        initializeList( &s, 1);
        
        for(int i=0; i < n; i++){
            eleType x;
            cin >> x;
            insert( &s, i, x);
        }
        
        eleType eMax = -100000, eMin = 100000, eSum = 0;
        
        for(int i = 0; i<size(&s); i++){
            eleType ele = getElement(&s, i);
            if(ele > eMax) eMax = ele;
            if(ele < eMin) eMin = ele;
            eSum += ele;
        }
        
        eSum -= eMax; // eSum = eSum - eMax
        eSum -= eMin; // eSum = eSum - eMin
        eSum /= ( n - 2); // eSum = eSum / (n-2)
        printf("%.2lf\n",eSum);
    }
    return 0;
}


