/** 
 * problem : https://leetcode.com/problems/queue-reconstruction-by-height/
 * algorithm : greedy
 * time complexity : O(NlogN)
 * 참고 : https://leetcode.com/problems/queue-reconstruction-by-height/discuss/2211643/C%2B%2B-oror-Easy-Solution-oror-Full-Explanation
 */
 
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b) { 
            if(a[0] == b[0]) return a[1] < b[1]; 
            return a[0] > b[0];
        });
        
        vector<vector<int>> answer;
        for(auto now: people) {
            answer.insert(answer.begin() + now[1], now);
        }
        return answer;
    }
};
