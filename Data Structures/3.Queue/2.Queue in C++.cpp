#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl; // 1
    q.pop();
    cout << q.front() << endl; // 2
    cout << q.size() << endl; // 2
    cout << q.empty() << endl; // 0

    return 0;
}