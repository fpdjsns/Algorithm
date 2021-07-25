/**
 * problem : https://leetcode.com/problems/word-ladder-ii/
 * algorithm : BFS
 * time complexity : O(N^2) // N = |wordList|
 */ 

class Solution {
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        int answerLen = -1;
        vector<vector<string>> answer = vector<vector<string>>();
        
        while(!q.empty()) {
            queue<vector<string>> nextQ;
            
            vector<pair<string, string>> todoDeleted;
            while(!q.empty()){
                vector<string> wordList = q.front();
                string lastWord = wordList.back();
                q.pop();

                if(lastWord == endWord) {
                    answer.push_back(wordList);
                    continue;
                }
                
                for(auto nextWord: dict[lastWord]) {
                    wordList.push_back(nextWord);
                    nextQ.push(wordList);
                    wordList.pop_back();
                    
                    todoDeleted.push_back({lastWord,nextWord});
                }
            }
            
            // delete edge
            for(auto deletedEdge: todoDeleted) {
                dict[deletedEdge.first].erase(deletedEdge.second);
                dict[deletedEdge.second].erase(deletedEdge.first);
            }

            // find answer
            if(!answer.empty()) break;
            q = nextQ;
        }
        
        return answer;
    }
};
