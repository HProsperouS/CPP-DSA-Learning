/*
Title:
1854. Maximum Population Year

Description:
You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
Return the earliest year with the maximum population.

Example 1:
	Input: logs = [[1993,1999],[2000,2010]]
	Output: 1993
	Explanation: The maximum population is 1, and 1993 is the earliest year with this population.

Example 2:
    Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
	Output: 1960
	Explanation: 
	The maximum population is 2, and it had happened in years 1960 and 1970.
	The earlier year between them is 1960.
	
Constraints:
	1 <= logs.length <= 100
	1950 <= birthi < deathi <= 2050
*/
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, int> populationChanges;

        // 记录每个年份的人口变化
        for (const auto& log : logs) {
            int birthYear = log[0];
            int deathYear = log[1];
            
            populationChanges[birthYear]++;  // 出生年份人口加一
            populationChanges[deathYear]--;  // 死亡年份人口减一
        }

        int maxPopulation = 0;
        int currentPopulation = 0;
        int earliestYear = INT_MAX;

        // 遍历从1950到2050年的每一年，计算每年的总人口
        for (int year = 1950; year <= 2050; ++year) {
            if (populationChanges.find(year) != populationChanges.end()) {
                currentPopulation += populationChanges[year];
            }

            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                earliestYear = year;
            }
        }

        return earliestYear;
    }
};