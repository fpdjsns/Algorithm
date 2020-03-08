/**
 * problem : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 * time complexity : O(N)
 */
class Solution {
public:
	int minFlips(int a, int b, int c) {
		int ans = 0;
		while (a > 0 || b > 0 || c > 0) {
			if (c % 2 == 1) 
				ans += !((a % 2) | (b % 2));
			else 
				ans += (a % 2) + (b % 2);
			a /= 2; b /= 2; c /= 2;
		}
		return ans;
	}
};
