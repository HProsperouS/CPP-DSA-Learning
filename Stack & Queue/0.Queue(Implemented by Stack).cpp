#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1; // 用于入队操作
    stack<int> stack2; // 用于出队操作

public:
    // 入队操作，将元素压入stack1
    void enqueue(int x) {
        stack1.push(x);
    }

    // 出队操作，从stack2中弹出元素
    int dequeue() {
        if (stack2.empty()) {
            // 如果stack2为空，将stack1中的元素逐个移动到stack2中
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // 如果stack2仍然为空，说明队列为空
        if (stack2.empty()) {
            throw runtime_error("Queue is empty");
        }

        int result = stack2.top();
        stack2.pop();
        return result;
    }

    // 返回队列的队首元素
    int front() {
        if (stack2.empty()) {
            // 如果stack2为空，将stack1中的元素逐个移动到stack2中
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // 如果stack2仍然为空，说明队列为空
        if (stack2.empty()) {
            throw runtime_error("Queue is empty");
        }

        return stack2.top();
    }

    // 判断队列是否为空
    bool empty() const {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element is: " << q.front() << endl; // 输出1

    cout << "Dequeued element is: " << q.dequeue() << endl; // 输出1
    cout << "Dequeued element is: " << q.dequeue() << endl; // 输出2

    q.enqueue(4);

    cout << "Dequeued element is: " << q.dequeue() << endl; // 输出3
    cout << "Front element is: " << q.front() << endl; // 输出4

    return 0;
}
