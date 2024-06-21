/*
Title:
LCP 07. Convey information

Description:
Child A is playing a message game with his friends. The rules of the game are as follows:

There are n players, all of whom are numbered from 0 to n-1, and child A is numbered 0
Each player has a fixed number of other players to whom information can be transmitted (or not). The information transfer relationship is one-way (for example, A can send information to B, but B cannot send information to A).
Each round of information must need to be passed to another person, and the information can be repeated through the same person
Given the total number of players n, and the two-dimensional array relation formed by the [player number, 
corresponding to the passable player number] relation. 
Returns the number of schemes passed from minor A (number 0) to the small partner (number n-1) after k rounds; 
If it cannot be reached, return 0.

Example 1:
	Input: n = 5, base = [[0, 2], [2, 1], [3, 4], [2, 3], [1, 4], [2, 0], [0, 4]], k = 3
	Output: 3
	Explanation: The message starts at 0 from small A and passes through 3 rounds to number 4. There are three schemes, respectively 0->2->0->4, 0->2->1->4, 0->2->3->4.

Example 2:
    Enter: n = 3, relation = [[0,2],[2,1]], k = 2
	Output: 0
	Explanation: Information cannot be passed from small A to number 2 after 2 rounds
	
Constraints:
	2 <= n <= 10
	1 <= k <= 5
	1 <= relation.length <= 90, and relation[i].length == 2
	0 <= relation[i][0],relation[i][1] < n and relation[i][0]! = relation[i][1]
	
*/
class Solution {
private:
    int matrix[10][10];
    int N;

    int dfs(int u, int k){
        if(k == 0){
            return (u == N-1) ? 1 : 0;
        }
        int sum = 0;
        for(int i=0; i<N; ++i){
            if(matrix[u][i]){
                sum += dfs(i, k-1);
            }
        }
        return sum;
    }
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        N=n;
        memset(matrix,0,sizeof(matrix));
        for(int i=0; i < relation.size(); i++){
            int a = relation[i][0];
            int b = relation[i][1];
            matrix[a][b] = 1;
        }
        return dfs(0,k);
    }
};