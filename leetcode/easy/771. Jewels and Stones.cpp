/**
 * problem : https://leetcode.com/problems/jewels-and-stones/
 * data structure : set
 * time complexity : O(N)
 */
 
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt = 0;
        set<char> dictionary;
        for(int i=0;i<J.size();i++){
            dictionary.insert(J[i]);
        }
        for(int i=0;i<S.size();i++){
            if(dictionary.find(S[i]) != dictionary.end()) 
                cnt++;
        }
        return cnt;
    }
};
