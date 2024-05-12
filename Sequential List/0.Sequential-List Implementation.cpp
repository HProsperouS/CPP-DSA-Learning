#include <iostream>
using namespace std;

// Define the type of elements stored in the list
#define eleType int

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

// Main function to test the sequential list
int main(){
    SequentialList myList; // Declare a sequential list
    initializeList( &myList, 10); // Initialize the list with a capacity of 10
    
    // Insert elements into the list
    for(int i=0; i < 10; ++i){
        insert(&myList, i, i*10);
    }
    
    // Display the size and emptiness status of the list
    cout << "Size: " << size(&myList) << endl;
    cout << "Is empty: "  << isEmpty( &myList ) << endl;
    
    // Display the elements of the list
    for(int i=0; i<size(&myList); ++i){
        cout << getElement( &myList,i ) << " ";
    }
    cout << endl;
    
    // Delete an element and update another element
    deleteElement( &myList, 5);
    updateElement( &myList, 1, 1314);
    
    // Display the updated elements of the list
    for(int i=0; i<size(&myList); ++i){
        cout << getElement( &myList,i ) << " ";
    }
    cout << endl;
    
    // Find an element, update it, and display the list
    int idx = findElement(&myList, 20);
    updateElement( &myList, idx, 520);
    for(int i=0; i<size(&myList); ++i){
        cout << getElement( &myList,i ) << " ";
    }
    cout << endl;
    
    // Destroy the list and deallocate memory
    destroyList( &myList );

    return 0;
}
