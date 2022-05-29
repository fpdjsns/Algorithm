/**
 * problem : https://leetcode.com/problems/maximum-product-of-word-lengths/
 * time complexity : O(N^2)
 * space complexity : O(N)
 * algorithm/data structure : bitmask
 */
 
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> bitmasks(n);
        for(int i = 0; i<n; i++){
            for(auto c: words[i]){
                bitmasks[i] |= (1<<(c-'a'));
            }
        }
        
        int answer = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((int)((bitmasks[i] & bitmasks[j]).to_ulong()) == 0){
                    answer = max(answer, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return answer;
    }
};
