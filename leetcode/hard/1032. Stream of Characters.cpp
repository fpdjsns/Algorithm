/**
 * problem : https://leetcode.com/problems/stream-of-characters/
 * data structure : Trie
 *
 * N = |words.length|, M = |words[i].length|, Q = |query|
 * time complexity : O(NM + MQ)
 * space complexity : O(NM)
 */
 
class TrieNode {
    public:
        unordered_map<char, TrieNode*> nexts;
        bool isLast = false;
    
        bool hasNext(char c) {
            return this->nexts.find(c) != this->nexts.end();
        }

        TrieNode* addNext(char c) {
            if(!hasNext(c))
                this->nexts[c] = new TrieNode();
            return this->nexts[c];
        }
};
    
class StreamChecker {
public:
    TrieNode* trie;
    string newStream = "";
    
    void addWord(const string& word) {
        TrieNode* node = trie;
        for(int i=word.size()-1; i>=0; i--){
            node = node->addNext(word[i]);
        }
        node->isLast = true;
    }
    
    bool findSuffix(const string& str) {
        TrieNode* node = trie;
        for(int i=str.size()-1; i>=0; i--){
            if(!node->hasNext(str[i])) return false;
            node = node->nexts[str[i]];
            if(node->isLast) return true;
        }
        return false;
    }
    
    StreamChecker(vector<string>& words) {
        trie = new TrieNode();
        for(auto word: words) addWord(word);
    }
    
    bool query(char letter) {
        newStream += letter;
        return findSuffix(newStream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
