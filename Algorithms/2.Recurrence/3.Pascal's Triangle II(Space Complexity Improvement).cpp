/*
Title:
119. Pascal's Triangle II

Description:
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
	Input: rowIndex = 3
	Output: [1,3,3,1]

Example 2:
    Input: rowIndex = 0
	Output: [1]

Example 3:
	Input: rowIndex = 1
	Output: [1,1]

Constraints:
	0 <= rowIndex <= 33
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int a[2][34];
        int now = 1, pre =0;
        a[pre][0] = 1;

        for(int i=1; i<=rowIndex; i++){
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i){
                    a[now][j] = 1;
                }else{
                    a[now][j] = a[pre][j] + a[pre][j-1]; 
                }
            }

            pre = 1 - pre;
            now = 1 - now;
        }

        vector<int> ret;

        for(int i=0; i<=rowIndex; i++){
            ret.push_back(a[pre][i]);
        }

        return ret;
    }

    /*
        1 0 0 0 0 
        1 1 0 0 0
        1 2 1 0 0
        1 3 3 1 0
        1 4 6 4 1
    */
};

