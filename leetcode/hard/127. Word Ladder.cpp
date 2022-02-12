/**
 * problem : https://leetcode.com/problems/word-ladder/
 * algorithm : BFS
 * time complexity : O(N^2) // N = |wordList|
 */
 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> dict;
        
        for(auto word: wordList) {
            dict[word] = unordered_set<string>();
            for(int i=0; i<word.size(); i++){
                string origin = word;
                for(char c = 'a'; c < 'z'; c++){
                    word[i] = c;
                    if(word == origin) continue;
                    
                    // 다른 단어에 있거나 beginWord 와 같다면
                    if(dict.find(word) != dict.end() || word == beginWord) {
                        dict[word].insert(origin);
                        dict[origin].insert(word);
                    }
                }
                word = origin;
            }
        }
        
        // word, number of words
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        
        set<string> visited;
        
        while(!q.empty()) {
            queue<pair<int, string>> nextQ;
            
            set<string> todoVisited;
            while(!q.empty()){
                int cnt = q.front().first;
                string lastWord = q.front().second;
                q.pop();

                if(lastWord == endWord) {
                    return cnt;
                }
                
                if(visited.find(lastWord) != visited.end()) continue; // already visited
                for(auto nextWord: dict[lastWord]) {
                    nextQ.push({cnt+1, nextWord});
                    todoVisited.insert(lastWord);
                }
            }
            
            for(auto vertex: todoVisited) {
                visited.insert(vertex);
            }

            q = nextQ;
        }
        return 0;
    }
};
