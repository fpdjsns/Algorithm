/*
 * 문제 : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * 시간복잡도 : O(N^2)
 * 알고리즘 : Greedy
 * 자료구조 : stack
 */
 
class Solution {
public:
	string reverseParentheses(string s) {
		vector<stack<char>> arr;
		string ans = "";
		int ind = -1;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c == '(') {
				arr.push_back(stack<char>());
				ind++;
			} else if (c == ')') {
				while (!arr[ind].empty()) {
					char tmp = arr[ind].top();
					if (arr.size() - 1 == 0)
						ans.push_back(tmp);
					else
						arr[ind - 1].push(tmp);
					arr[ind].pop();
				}

				arr.pop_back();
				ind--;
			} else {
				if (ind == -1) {
					ans += c;
				} else {
					arr[ind].push(c);
				}
			}
		}
		return ans;
	}
};
