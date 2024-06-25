#include <iostream>
#include <queue>

using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;
    
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }
    
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // 或者抛出异常
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
