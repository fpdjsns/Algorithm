/*
 * 문제 : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * 시간복잡도 : O(NM * logK) // N: words.length , M: words[i].length, K: chars.length
 * 자료구조 : Map
 */

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int> m;
        for(int i=0; i<chars.size(); i++){
            m[chars[i]]++;
        }
        
        int answer = 0;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            map<char,int> charsMap = m;
            bool canAns = true;
            for(int j=0;j<word.size(); j++){
                char nowChar = word[j];
                charsMap[nowChar]--;
                if(charsMap[nowChar] < 0) {
                    canAns = false;
                    break;
                }
            }
            if(canAns) answer += word.size();
        }
        return answer;
    }
};
