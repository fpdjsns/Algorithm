/**
 * problem : https://leetcode.com/problems/add-strings/
 * time complexity : O(N) // N = |num1|, |num2| 중 큰 값 
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int ind1 = n-1;
        int ind2 = m-1;
        int c = 0;
        string answer;
        
        while(ind1 >= 0 || ind2 >= 0 || c > 0) {
            int a = 0; int b = 0;
            if(ind1 >= 0) a = num1[ind1--] - '0';
            if(ind2 >= 0) b = num2[ind2--] - '0';
            answer.insert(0, 1, ((a + b + c) % 10) + '0'); 
            c = (a + b + c) / 10;
        }
        
        return answer;
    }
};
