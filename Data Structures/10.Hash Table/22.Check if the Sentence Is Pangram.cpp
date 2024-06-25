/*
Title:
	1832. Check if the Sentence Is Pangram
Description:
	A pangram is a sentence where every letter of the English alphabet appears at least once.
	Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, 
	or false otherwise.

Example 1:
	Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
	Output: true
	Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:
	Input: sentence = "leetcode"
	Output: false
	
Constraints:
	1 <= sentence.length <= 1000
	sentence consists of lowercase English letters.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> alphabetSet;
        for (char c = 'a'; c <= 'z'; ++c) {
            alphabetSet.insert(c);
        }

        for(auto &word : sentence){
            if(alphabetSet.find(word) != alphabetSet.end()){
                alphabetSet.erase(word);
            }
        }
        
        if(alphabetSet.size() == 0) return true;
        return false;
    }
};