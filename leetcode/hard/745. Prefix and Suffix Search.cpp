/**
 * problem : https://leetcode.com/problems/prefix-and-suffix-search/
 * time complexity : O(N(M^2))(init), O(M)
 *     N = words.length, M = words[i].length, prefix.length, suffix.length
 * algorithm : Trie
 * refer : https://leetcode.com/problems/prefix-and-suffix-search/discuss/2165021/C%2B%2B-oror-Using-single-Trie-oror-Detailed-Explanation 
 */
 
class TrieNode {
public:
    unordered_map<char, TrieNode*> nexts;
    int index;

    bool hasNext(char c) {
        return this->nexts.find(c) != this->nexts.end();
    }

    TrieNode* addNext(char c, int index) {
        if(!hasNext(c))
            this->nexts[c] = new TrieNode();
        (this->nexts[c]->index) = max((this->nexts[c]->index),index);
        return this->nexts[c];
    }
};  

class WordFilter {    
public:
    TrieNode* trie;
    char DASH = '-';
    WordFilter(vector<string>& words) {
        trie = new TrieNode();
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            string str = DASH + words[i];
            add(str, i);
            for(int j=word.size()-1; j>=0; j--){
                str = word[j] + str;
                add(str, i);            
            }
        }
    }

    void add(const string& word, int index) {
        TrieNode* node = trie;
        int n = word.size();
        for(auto c: word) {
            node = node->addNext(c, index);
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* node = trie;
        string word = suffix + DASH + prefix;
        for(auto c: word){
            if(!node->hasNext(c)) return -1;
            node = node->nexts[c];
        }
        return node->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
