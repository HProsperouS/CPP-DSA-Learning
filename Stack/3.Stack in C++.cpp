#include <iostream>
#include <stdexcept>
#include <stack>

using namespace std;

int main() {

    stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(3);
    while (!intStack.empty()) {
        cout << intStack.top() << ' ';
        intStack.pop();
    }   // 3 3 2 1

    return 0;
}

/*
1. empty() – Returns whether the stack is empty – Time Complexity : O(1)
2. size() – Returns the size of the stack – Time Complexity : O(1)
3. top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
4. push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
5. pop() – Deletes the top most element of the stack – Time Complexity : O(1)
*/