/*
Title:
Base-Convertion

Description:
Input a decimal number N and convert it to a base R number output.

Input:
	The input data contains multiple test instances, each containing two integers N(32-bit integer) and R (2<=R<=16, R<>10).
Output:
    Output the converted number for each test instance, one line per output. If R is greater than 10, then the corresponding number rules refer to hexadecimal (for example, 10 is represented by A, and so on).
	
Sample Input:
    7 2
    23 12
    -4 3

Sample Output:
	1
    10
    11
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, r;
    while (cin >> n >> r) {
        if(n == 0) {
            cout << 0 << endl;
            continue;
        }

        if(n < 0) {
            cout << "-";
            n = -n;
        }

        stack<int> stk;
        while (n) {
            stk.push(n % r);
            n /= r;
        }
        while (!stk.empty()) {
            int x = stk.top();
            stk.pop();
            if(x < 10) {
                cout << x;
            } else {
                cout << (char)('A' + x - 10);
            }
        }
        cout << endl;
    }

    return 0;
}