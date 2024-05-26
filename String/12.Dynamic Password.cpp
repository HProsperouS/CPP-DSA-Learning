/*
Title:
	LCR 182. Dynamic password

Description:
The access password of a company uses the dynamic password technology. 
The initial password is a character string password. 
Follow the following steps to update the password:
	Set a positive integer target value
	Move the target character before password to the end of the string in the original order
	Please return the updated password string.

Example 1:
	Input: password = "s3cur1tyC0d3", target = 4
	Output: "r1tyC0d3s3cu"

Example 2:
	Input: password = "lrloseumgh", target = 6
	Output: "umghlrlose"
    
Constraints:
	1 <= target < password.length <= 10000
	
*/

class Solution {
public:
    string dynamicPassword(string password, int target) {
    //     return password.substr(target) + password.substr(0,target);

    std::string ret;
    int n = password.length();
    
    for(int i = 0; i < n; i++){
        int index = (i + target) % n;
        ret += password[index];
    }

    return ret;
    }
};
