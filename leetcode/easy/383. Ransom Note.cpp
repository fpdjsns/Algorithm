/** 
 * problems : https://leetcode.com/problems/ransom-note/
 * data structure : map 
 * time complexity : O(N + M) // N = |magazine|, M = |ransomNote|
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> words;
        for(int i=0;i<magazine.size();i++){
            words[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(words[ransomNote[i]] <= 0) return false;
            words[ransomNote[i]]--;
        }
        return true;
    }
};
