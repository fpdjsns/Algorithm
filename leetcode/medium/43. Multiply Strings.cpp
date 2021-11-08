/**
 * problem : https://leetcode.com/problems/multiply-strings/
 * time complexity : O(NM)
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        
        vector<int> calc(n + m, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int multi = (num1[i] - '0') * (num2[j] - '0') + calc[i + j + 1];
                calc[i + j + 1] = multi % 10;
                calc[i + j] += multi / 10;
            }
        }
        
        int ind = 0;
        while(ind < n + m && calc[ind] == 0) ind++;
        string answer;
        while(ind < n + m) answer.push_back(calc[ind++] + '0');
        if(answer.size() == 0) answer = "0";
        
        return answer;
    }
};
