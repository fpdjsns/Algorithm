/**
 * problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * time complexity : O(N)
 * algorithm : two-pointer
 */

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int ind = 1;
		int start = prices[0];
		int ans = 0;
		int end = prices[0];
		for (int ind = 0; ind < prices.size(); ) {

			// find increase
			int start = -1;
			for (; ind<prices.size() - 1; ind++) {
				if (prices[ind + 1] > prices[ind]) {
					start = prices[ind];
					break;
				}
			}
			if (start == -1) break; // not found increase

			// find decrease
			int end = -1;
			for (; ind<prices.size()-1; ind++) {
				if (prices[ind + 1] < prices[ind]) {
					end = prices[ind];
					break;
				}
			}
			// not found decrease
			if (end == -1) {
				end = prices[ind];
				if (start >= end)
					break;
			}

			ans += end - start;
		}
		return ans;
	}
};
