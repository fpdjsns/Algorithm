/**
 * problem : https://leetcode.com/problems/minimum-window-substring/
 * time complexity : O(N+M)
 * algorithm : two-pointer
 */

class Solution {
public:

    string minWindow(string s, string t) {
        int m = s.size(); int n = t.size();
        unordered_map<char, int> cnts;
        for (auto c : t) cnts[c]++;

        int left = 0;
        int cnt = n;
        pair<int, int> answer = { -1, m + 1 }; // start, end
        for (int right = 0; right<m; right++) {
            char c = s[right];
            cnts[c]--;
            if (cnts[c] >= 0) {
                cnt--;
                if (left == -1) left = right;
            }
            if (cnt > 0) continue; // can not answer

            // set left
            while (left <= right) {
                if (cnt >= 0 && cnts[s[left]] >= 0) break;
                cnts[s[left]]++;
                if (cnts[s[left]] > 0) cnt++;
                left++;
            }

            if (right - left + 1 < answer.second) {
                answer = { left, right - left + 1 };
            }
        }

        if (answer.second == m + 1) return "";
        return s.substr(answer.first, answer.second);
    }
};
