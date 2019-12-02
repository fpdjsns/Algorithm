
/**
 * 문제 : https://programmers.co.kr/learn/courses/30/lessons/60060
 */
 
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Element {
public:
	string s;
	vector<Element*> next;
	bool isEnd = false;

	Element() {}

	Element(string _s) {
		s = _s;
		next = vector<Element*>(26, NULL);
		isEnd = false;
	}
};

vector<vector<Element*>> v(10000, vector<Element*>());
Element* root = NULL;
void makeTrie(string word) {
	if (word.size() == 0) return;
	if (root == NULL) root = new Element("");

	Element* e = root;
	string tmp = "";
	for (int i = 0; i < word.size(); i++) {
		int now = word[i] - 'a';
		tmp += now;
		if ((e->next).size() == 0 || (e->next)[now] == NULL) {
			Element* newE = new Element(tmp);
			(e->next)[now] = newE;
			e = newE;
			v[i].push_back(newE);
		}
		else {
			e = (e->next)[now];
		}
	}
	e->isEnd = true;
}

int findWord(string query, Element* now) {
	if (query.size() == 0)
		return now->isEnd;
	
	int cnt = 0;
	int c = query[0]-'a';
	vector<Element*> m = now->next;
	string nextQuery = query.substr(1, query.size() - 1);

	if (c == '?') {
		for (int i = 0; i < m.size();i++) {
			if (m[i] == NULL) continue;
			cnt += findWord(nextQuery, m[i]);
		}
	} else {
		if(m[c] != NULL) cnt += findWord(nextQuery, m[c]);
	}
	return cnt;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer(queries.size());
	for (int i = 0; i < words.size(); i++) {
		makeTrie(words[i]);
	}
	for (int i = 0; i < queries.size(); i++) {
		string q = queries[i];
		int s = q.size()-1; int e = 0;
		for (int j = 0; j < q.size(); j++) {
			if (q[j] != '?') continue;
			s = min(s, j); e = max(e, j);
		}
		if (s == 0 && e == q.size() - 1) answer[i] = v[q.size()].size(); // all '?'
		else if (s == 0) {	// 접두사 (??aaa)
			int cnt = 0;
			for (int k = 0; k < v[e].size(); k++) {
				cnt += findWord(q.substr(e + 1, q.size() - (e + 1)), v[e][k]);
			}
			answer[i] = cnt;
		}
		else { // 접미사 (aa???)
			answer[i] = findWord(queries[i], root);
		}
	}

	return answer;
}

int main() {
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	solution(words, words);
	return 0;
}
