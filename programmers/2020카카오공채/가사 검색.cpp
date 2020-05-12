/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/60060
 * algorithm : Trie
 * time complexity : O(NM) //let, N = |words| or |queries|, M = |words[i]| or |queries[i]|
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Node {
public:
	map<int,int> cntMap; // key = length, value = cnt
	vector<Node*> next;

	Node() {
		next = vector<Node*>(26, NULL);
	}

	void addWord(string word) {
		cntMap[word.size()]++;
	}
};

Node* makeTrie(vector<string> words) {

	Node* root = new Node();

	for (int j = 0; j < words.size(); j++) {
		Node* node = root;
		string word = words[j];
		node->addWord(word);
		for (int i = 0; i < word.size(); i++) {
			int now = word[i] - 'a';
			if ((node->next)[now] == NULL) {
				Node* newNode = new Node();
				(node->next)[now] = newNode;
				node = newNode;
			}
			else {
				node = (node->next)[now];
			}
			node->addWord(word);
		}
	}
	return root;
}


int findWord(string word, Node* root) {
	Node* node = root;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == '?') 
			return (node->cntMap)[word.size()];
		int now = word[i] - 'a';
		node = node->next[now];
		if(node == NULL) return 0;
	}
	return 0;
}

int findPrefixWord(string word, Node* root) {
	return findWord(word, root);
}
int findSuffixWord(string word, Node* root) {
	reverse(word.begin(), word.end());
	return findWord(word, root);
}

vector<int> solution(vector<string> words, vector<string> queries) {
	Node* prefixRoot = makeTrie(words);
	vector<string> reverseWords(words.size());
	for (int i = 0; i < words.size(); i++) {
		string reverseWord = words[i];
		reverse(reverseWord.begin(), reverseWord.end());
		reverseWords[i] = reverseWord;
	}
	Node* suffixRoot = makeTrie(reverseWords);

	vector<int> answer(queries.size());
	for (int i = 0; i < queries.size(); i++) {
		if(queries[i][0] == '?')answer[i] = findSuffixWord(queries[i], suffixRoot);
		else answer[i] = findPrefixWord(queries[i], prefixRoot);
	}

	return answer;
}
