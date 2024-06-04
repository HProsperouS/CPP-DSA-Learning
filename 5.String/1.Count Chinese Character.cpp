/*
Title:
Count chinese character

Description
Counts the number of characters in a given text file.


Input
The input file first contains an integer n, representing the number of test instances, followed by n segments of text.


Output
For each paragraph of text, output the number of characters in it, and the output of each test instance is one line.

[Hint:] Considering the characteristics of the inner code of the Chinese character machine ~



Sample Input
2
WaHaHa! WaHaHa! 今年过节不说话要说只说普通话WaHaHa! WaHaHa!
马上就要期末考试了Are you ready?


Sample Output
14
9
*/

#include <iostream>
#include <string>
using namespace std;

bool isChineseCharacter(unsigned char c1, unsigned char c2, unsigned char c3) {
    return (c1 >= 0xE4 && c1 <= 0xE9) &&
           (c2 >= 0x80 && c2 <= 0xBF) &&
           (c3 >= 0x80 && c3 <= 0xBF);
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string text;
        getline(cin, text); 

        int chineseCount = 0;
        for (size_t j = 0; j < text.length(); ++j) {
            if (j + 2 < text.length() && isChineseCharacter((unsigned char)text[j], (unsigned char)text[j + 1], (unsigned char)text[j + 2])) {
                ++chineseCount;
                j += 2; 
            }
        }
        cout << chineseCount << endl; 
    }

    return 0;
}