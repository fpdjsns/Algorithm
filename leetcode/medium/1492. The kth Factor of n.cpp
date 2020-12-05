/**
 * problem : https://leetcode.com/problems/the-kth-factor-of-n/
 * time complexity : O(sqrt(N))
 */

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> answers;
        for(int i=1; i * i <= n; i++){
            if(n % i != 0) continue;
            k--;
            if(k == 0) return i;
            if(i * i == n) continue;
            answers.push_back(n / i);
        }
        
        if(answers.size() < k) return -1;
        return *(answers.rbegin() + k - 1);
    }
};
