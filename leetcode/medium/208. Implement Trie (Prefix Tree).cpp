/**
 * problem : https://leetcode.com/problems/implement-trie-prefix-tree/
 * time complexity : O(Q * logN) // N = |word|, |prefix|, Q = |Query|
 * algorithm : Trie
 */

class Node {
    char value;
public:
    bool isEnd = false;
    vector<Node*> children;
    
    Node() { }
    Node(char c) {
        value = c;
        isEnd = false;
        children = vector<Node*>(26, NULL);
    }
};

class Trie {
    Node root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = Node(' ');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* now = &root;
        for(int i=0;i<word.size();i++){
            Node* node = now->children[word[i]-'a'];
            if(node == NULL)
                node = new Node(word[i]);
            now->children[word[i]-'a'] = node;
            now = node;
        }
        now->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* now = &root;
        for(int i=0;i<word.size();i++){
            now = now->children[word[i]-'a'];
            if(now == NULL)
                return false;
        }
        return now->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* now = &root;
        for(int i=0;i<prefix.size();i++){
            now = now->children[prefix[i]-'a'];
            if(now == NULL)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
