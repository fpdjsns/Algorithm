/*
 * 문제 : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * 시간복잡도 : O(N)
 * 알고리즘 : Greedy
 * 자료구조 : Stack
 */
 
class Solution {
public:
	string removeDuplicates(string s, int k) {
		stack<pair<char, int>> st; // {s[i], s[i]문자가 연속으로 나온 수} 
		for (int i = 0; i<s.size(); i++) {
			char c = s[i];

			if (st.empty() || st.top().first != c) {
				st.push({ c, 1 });
			}
			else {
				int& cnt = st.top().second;
				st.top().second++;
                		if(cnt == k) st.pop();
			}
		}
		string ans = "";
		while (!st.empty()) {
			pair<int, int> ele = st.top();
			st.pop();
			string tmp = "";
			for (int i = 0; i<ele.second; i++) {
				tmp += ele.first;
			}
			ans = tmp + ans;
		}
		return ans;
	}
};
