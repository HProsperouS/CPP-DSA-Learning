#include <iostream>
#include <vector>
using namespace std;

// Question: Find the product of odd numbers
// Problem Description: Given n integers, find the product of all odd numbers among them

// Input: The input data contains multiple test instances, each test instance occupies a line, the first number in each line is n, which means that there are a total of n data in this group, followed by n integers, you can assume that there must be an odd number in each group of data.

// Output:Output the product of all odd numbers in each set of numbers. For each test case, output one line.

// Sample Input 1: 3 1 2 3 
// Sample Output 1: 3

// Sample Input 1: 4 2 3 4 5
// Sample Output 2: 15

int main(){
    int n;
    while(cin >> n) {
        cout << "n is " << n << endl;
        vector<int> array(n);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            array[i] = x;
        }
        
        // s.size == n
        int prod = 1;
        for(int i = 0; i < n; i++){
            int val = array[i];
            if (val % 2 == 1){
                prod *= val; 
            }
        }
        cout << prod << endl;
    }
    
    return 0;
}
