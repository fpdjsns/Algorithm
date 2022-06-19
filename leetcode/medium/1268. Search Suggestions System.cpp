/**
 * problem : https://leetcode.com/problems/search-suggestions-system/
 * time complexity : O(NM) 
 *       N = product.length, M = product[i].length
 * algorithm : Trie
 */
 
class TrieNode {
    public:
        unordered_map<char, TrieNode*> nexts;
        vector<string> words;
    
        bool hasNext(char c) {
            return this->nexts.find(c) != this->nexts.end();
        }

        TrieNode* addNext(char c, const string& word) {
            if(!hasNext(c))
                this->nexts[c] = new TrieNode();
            TrieNode* next = this->nexts[c];
            vector<string>& ret = next->words;
            ret.push_back(word);
            sort(ret.begin(), ret.end());
            if(ret.size() > 3) ret.pop_back();
            return next;
        }
};

class Solution {
public:
    TrieNode* trie;
    
    void addWord(const string& word) {
        TrieNode* node = trie;
        for(auto c: word){
            node = node->addNext(c, word);
        }
    }
        
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        trie = new TrieNode();
        for(auto product: products) {
            addWord(product);
        }
        
        vector<vector<string>> answer;
        TrieNode* node = trie;
        bool notFound = false;
        for(char c: searchWord) {
            if(notFound || !node->hasNext(c)) {
                notFound = true;
                answer.push_back({});
                continue;
            }
            node = node->nexts[c];
            answer.push_back(node->words);
        }
        return answer;
    }
};
