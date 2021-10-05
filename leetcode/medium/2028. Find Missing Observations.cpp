/**
 * problem : https://leetcode.com/problems/find-missing-observations/
 * time complexity : 
 */

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        for(auto num: rolls) {
            sum -= num;
        }
        
        vector<int> answer(n, sum / n);
        int avg = sum / n;
        int namuge = sum % n;
        if(avg + (namuge > 0) > 6 || avg < 1) return {};
        for(int i=0; i<namuge; i++){
            answer[i]++;
        }
        return answer;
    }
};
