/**
 * problem : https://leetcode.com/problems/sequential-digits/
 * time complexity : O(1)
 */
 
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        for(int i=1; i<= 9; i++) {
            int tmp = i;
            for(int j=i+1; j<=9; j++){
                tmp = tmp * 10 + j;
                if(tmp < low) continue;
                if(tmp > high) break;
                answer.push_back(tmp);
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};
