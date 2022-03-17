/**
 * problem : https://leetcode.com/problems/score-of-parentheses/
 * time complexity : O(N^2)
 */

class Solution {
public:
	int scoreOfParentheses(string s) {
		stack<int> st;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] == '(') {
				st.push(0);
			}
			else {
				int sum = 0;
				while (!st.empty() && st.top() != 0) {
					sum += st.top();
					st.pop();
				}
				st.pop();
				st.push(sum == 0 ? 1 : sum * 2);
			}
		}

		int answer = 0;
		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}

		return answer;
	}
};
