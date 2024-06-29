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
        int a[34][34];
        for(int i=0; i<=rowIndex; i++){
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i){
                    a[i][j] = 1;
                }else{
                    a[i][j] = a[i-1][j] + a[i-1][j-1]; 
                }
            }
        }

        vector<int> ret;

        for(int i=0; i<=rowIndex; i++){
            ret.push_back(a[rowIndex][i]);
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
