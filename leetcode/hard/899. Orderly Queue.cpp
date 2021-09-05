/**
 * problem : https://leetcode.com/problems/orderly-queue/
 * time complexity : O(NlogN)
 * algorithm : greedy
 */
 
class Solution {
public:
    string orderlyQueue(string S, int K) {
        string ans = S;
        if(K==1){
            for(int i=1; i<S.size();i++)
                ans = min(ans, S.substr(i) + S.substr(0, i));
        }else{
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};
