/*
Title:
LCR 169. Move Disassembly II

Description:
A combo move is written as a sequence arr consisting of only lowercase letters, 
where arr[i] is the name of the I-th move. 
Return the name of the first move that appears only once, or a space if it does not exist.


Example 1:
	Enter: arr = "abbccdeff"
	Output: 'a'

Example 2:
    Input: arr = "ccdd"
	Output: ' '
	
Constraints:
	0 <= arr.length <= 50000
	
*/
class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<char, int> frequency;
        for(char ch:arr){
            frequency[ch]++;
        }

        for(int i=0; i<arr.size(); i++){
            if(frequency[arr[i]] == 1){
                return arr[i];
            }
        }
        return ' ';
    }
};