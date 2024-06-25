/*
Title:
面试题 16.02. Words Frequency LCCI

Description:
Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm multiple times?
You should implement following methods:
WordsFrequency(book) constructor, parameter is a array of strings, representing the book.
get(word) get the frequency of word in the book. 

Example:
WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
wordsFrequency.get("you"); //returns 0，"you" is not in the book
wordsFrequency.get("have"); //returns 2，"have" occurs twice in the book
wordsFrequency.get("an"); //returns 1
wordsFrequency.get("apple"); //returns 1
wordsFrequency.get("pen"); //returns 1

Constraints:
	There are only lowercase letters in book[i].
	1 <= book.length <= 100000
	1 <= book[i].length <= 10
	get function will not be called more than 100000 times.
*/
class WordsFrequency {
private:
    unordered_map<string,int> frequencyMap; 
public:
    WordsFrequency(vector<string>& book) {
        for(auto &word : book){
            frequencyMap[word]++;
        }
    }
    
    int get(string word) {
        return frequencyMap[word];
    }
};