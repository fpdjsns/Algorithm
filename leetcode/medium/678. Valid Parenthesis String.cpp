/**
 * problem : https://leetcode.com/problems/valid-parenthesis-string/
 * data structure : stack, deque 
 * time complexity : O(N)
 */

class Solution {
public:
    bool checkValidString(string s) {
		stack<int> open;
		deque<int> star;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] == '*') star.push_back(i);
			else if (s[i] == '(') open.push(i);
			else {
				if (open.empty()) {
					if (star.empty()) return false;
					else star.pop_front();
				}
				else {
					open.pop();
				}
			}
		}
		if (open.size() > star.size()) return false;
		while (!open.empty()) {
			if (open.top() > star.back()) return false;
			open.pop();
			star.pop_back();
		}
		return true;
    }
};
