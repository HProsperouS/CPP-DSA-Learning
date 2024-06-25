/*
Title:
Bitset

Description:
Give you a number on base ten, you should output it on base two.(0<n<1000)

Input:
	For each case, there is a positive number n on base ten.

Output:
    For each case output the number on base two.
	
Sample Input:
    1   
    2
    3

Sample Output:
	1
    10
    11
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> stk;
        while (n) {
            stk.push(n % 2);
            n /= 2;
        }
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }

    return 0;
}