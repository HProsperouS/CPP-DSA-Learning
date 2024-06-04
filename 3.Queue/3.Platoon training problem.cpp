/*
Title:
Platoon training problem

Description:
The new recruits are numbered in order from the beginning and lined up in a row. 
The training rules are as follows: Start from one to two, where the column of report two, 
the rest move closer to the direction of small serial number, and then start from one to three, 
where the column of report three, the rest move closer to the 
direction of small serial number, and continue to start from one to two. 
After that, it will take turns to count from one to two and from one to three until 
there are no more than three people left.

Input:
There are multiple test data sets, first the number of behavior groups N, 
and then the number of new recruits in N rows, the number of new recruits is not more than 5000.

Ouput:
There are N lines, each corresponding to the number of recruits entered, 
and each line outputs the original number of the remaining recruits, 
with a space between the numbers.

Sample Input:
	2
	20
	40

Sample Ouput:
	1 7 19
	19 37

*/

// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>

using namespace std;
int main() {
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        queue<int> q1, q2;
        
        for(int i = 1; i <= n; i++){
            q1.push(i);
        }
        while( q1.size() > 3 ){
            int count = 0;
            while( q1.size() ){
                int val = q1.front();
                q1.pop();
                ++count;
                if(count % 2 == 1){
                    q2.push(val);
                }
            }
            
            if(q2.size() <= 3){
                while(q2.size()){
                    int val = q2.front();
                    q2.pop();
                    q1.push(val);
                }
                break;
            }
            count = 0;
            while( q2.size() ){
                int val = q2.front();
                q2.pop();
                ++count;
                if(count % 3 != 0){
                    q1.push(val);
                }
            }
        }
        
        int flag = 0;
        while(q1.size()){
            if(flag){
                cout << ' ';
            }
            cout << q1.front();
            q1.pop();
            flag++;
        }
        cout << endl;
    }

    return 0;
}