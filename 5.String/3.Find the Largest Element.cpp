/*
Title:
Find the largest element

Problem Description
For each string entered, find the largest letter in it and insert the string "(max)" after that letter.

Input
The input data consists of multiple test instances, each consisting of a string of up to 100 characters in length, consisting only of upper and lower case letters.

Output
For each test instance output a string, the output result is the result of inserting the string "(max)", if there are more than one largest letter, insert "(max)" after each largest letter
    
Sample Input
	abcdefgfedcba
	xxxxx
 
Sample Output
	abcdefg(max)fedcba
	x(max)x(max)x(max)x(max)x(max)
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string line; 
    while ( getline(cin, line) ) {
        string res = "";
        int len = line.length();
        char maxc = line[0];
        
        for (int i = 1; i < len; ++i) {
            if( line[i] > maxc){
                maxc = line[i];
            }
        }
        
        for(int i=0; i < len; ++i){
            res = res + line[i];
            if(line[i] == maxc){
                res = res + "(max)";
            }
        }
        
        cout << res << endl; 
    }
    return 0;
}

