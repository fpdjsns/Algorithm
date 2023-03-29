/**
 * problem : https://leetcode.com/problems/reducing-dishes/description/
 * time complexity : O(N^2)
 */
 
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += satisfaction[i];
        }
        
        int answer = 0;        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += satisfaction[j] * (j-i+1);
            }
            answer = max(answer, sum);
        }
        return answer;
    }
};
