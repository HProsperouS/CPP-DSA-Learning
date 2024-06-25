/*
Title:
Capitalize the first letter

Problem Description
Type an English sentence and capitalize the first letter of each word.

Input
The input data consists of multiple test instances, each of which is an English sentence of no more than 100 in length, covering a single line.

Output
Please output the revised English sentence as required.
	
Sample Input
	i like acm
	i want to get an accepted

Sample Output
	I Like Acm
	I Want To Get An Accepted
	
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char line[101]; 
    while (cin.getline(line, 101)) {
        int len = strlen(line);
        bool newWord = true; 

        for (int i = 0; i < len; ++i) {
            if (line[i] == ' ') {
                newWord = true; 
            } else if (newWord) {
                line[i] = toupper(line[i]); 
                newWord = false; 
            }
        }
        cout << line << endl; 
    }
    return 0;
}

