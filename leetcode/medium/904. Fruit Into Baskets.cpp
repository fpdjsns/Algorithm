/*
 * 문제 : https://leetcode.com/problems/fruit-into-baskets/description/
 * 시간복잡도 : O(N)
 * 알고리즘 : Two Pointer
 */

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int ans = 0;
		int l = 0;
		int r = 0;
		unordered_map<int, int> m;

		int now = -1;
		int another = -1; 
		for (l = 0; l<tree.size(); l++) {
			if (tree[l] == another){
				if (m[now] > l)
					another = now;
				else
					another = -1;
			}
	
			now = tree[l];
			while (r + 1<tree.size() && !(another != -1 && tree[r + 1] != now && tree[r + 1] != another)) {
				r++;
				m[tree[r]] = r;
				if (tree[r] != now)
					another = tree[r];
			}
			ans = max(ans, r - l + 1);
		}
		return ans;
	}
};
