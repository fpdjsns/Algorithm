/**
 * problem : https://leetcode.com/problems/check-if-n-and-its-double-exist/
 * time complexity : O(NlogN)
 */

class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		sort(arr.begin(), arr.end(), [arr](int& a, int& b) {
			if (a < 0 && b < 0) return a > b;
			return a < b;
		});
		set<int> s;
		bool ans = false;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] % 2 == 0 && s.find(arr[i] / 2) != s.end()){
				ans = true;
				break;
			}
			s.insert(arr[i]);
		}
		return ans;
	}
};
