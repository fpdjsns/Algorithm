/**
 * problem : https://leetcode.com/problems/add-binary/
 * time complexity : O(N)
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        int aInd = a.size()-1;
        int bInd = b.size()-1;
        int c = 0;
        while(aInd >= 0 && bInd >= 0){
            c += a[aInd--] - '0' + b[bInd--] - '0';
            answer.push_back(c % 2 + '0');
            c /= 2;
        }
        while(aInd >= 0) {
            c += a[aInd--] - '0';
            answer.push_back(c % 2 + '0');
            c /= 2;
        }
        while(bInd >= 0) {
            c += b[bInd--] - '0';
            answer.push_back(c % 2 + '0');
            c /= 2;
        }
        if(c > 0) answer.push_back('1');
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
