/**
 * problem : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
 * time complexity : O(|s|)
 */

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        string tmp = "";
        unordered_set<string> dict;
        for(auto c: s) {
            tmp.push_back(c);
            if(tmp.size() > k) tmp.erase(0, 1);
            if(tmp.size() == k) dict.insert(tmp);
        }
        return dict.size() == pow(2, k);
    }
};
