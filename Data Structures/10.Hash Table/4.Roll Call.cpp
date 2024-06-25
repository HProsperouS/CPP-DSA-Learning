/*
Title:
LCR 173. Roll Call

Description:
The student numbers of n students in a class range from 0 to n-1. 
The roll call results are recorded in the ascending array records. 
If only one student is absent, please return his student number.


Example 1:
	Enter: records = [0,1,2,3,5]
	Output: 4
	
Example 2:
	Enter: records = [0, 1, 2, 3, 4, 5, 6, 8]
	Output: 7

Tip:
	1 <= records.length <= 10000
*/
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        unordered_map<int,int> hashTable;
        for(int i=0; i<records.size(); i++){
            hashTable[ records[i] ] = 1;
        }

        for(int i=0; ;i++){
            if(hashTable.find(i) == hashTable.end()) return i;
        }

        return -1;
    }
};