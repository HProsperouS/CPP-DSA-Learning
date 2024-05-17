/*
Title:
Leetcode 面试题 03.04. Implement Queue using Stacks LCCI

Description:
Implement a MyQueue class which implements a queue using two stacks.

Example :
	MyQueue queue = new MyQueue();

	queue.push(1);
	queue.push(2);
	queue.peek();  // return 1
	queue.pop();   // return 1
	queue.empty(); // return false

Notes:
	You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
	Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
	You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/


class MyQueue {   
private:
    stack<int> inputStack;
    stack<int> outputStack;

    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        transferIfNeeded();
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }

    int peek() {
        transferIfNeeded();
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */