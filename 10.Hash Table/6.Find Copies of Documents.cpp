/*
Title:
LCR 120. Find Copies of Documents

Description:
There are n files in the device, and the file id is recorded in the array documents. 
If the file id is the same, the file is defined as having a duplicate. 
Return the id of any file that has a copy.

Example 1:
	Input: documents = [2, 5, 3, 0, 5, 0]
	Output: 0 or 5
	
Constraints:
	0 ≤ documents[i] ≤ n-1
	2 <= n <= 100000
*/
class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        unordered_map<int, bool> map;
        for(int doc : documents) {
            if(map[doc]) return doc;
            map[doc] = true;
        }
        return -1;
    }
};