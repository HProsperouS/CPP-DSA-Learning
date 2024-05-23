/*
Title:
LCR 122. Path encryption

Description:
Suppose a path is denoted as the string path, with "." as the separator. 
You need to encrypt the path by replacing the separator in path with a space "", and return the encrypted string.

Example 1:
	Enter: path = "a.af.qerf.bb"
	Output: "a aef qerf bb"
    
	
Constraints:
	0 <= path.length <= 10000
	
*/

class Solution {
public:
    string pathEncryption(string path) {
        int len = path.size();
        for(int i=0; i < len; i++){
            if(path[i] == '.') path[i] = ' ';
        }

        return path;
    }
};
