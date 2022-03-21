/**
 * problem : https://leetcode.com/problems/partition-labels/
 * time complexity : O(N)
 */

class Solution {
public:
    
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector<pair<int, int>> arr(26, { -1, -1 });
        for (int i = 0; i<len; i++) {
            pair<int, int>& now = arr[S[i] - 'a'];
            if (now.first == -1)
                now.first = now.second = i;
            else
                now.second = i;
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int last = -1;
        int beforeInd = -1;
        for (int i = 0; i<arr.size(); i++) {
            if (arr[i].first == -1) continue;

            if (last == -1 || arr[i].first < last) {
                last = max(last, arr[i].second);
            }
            else {
                ans.push_back(last - beforeInd);
                beforeInd = last;
                last = arr[i].second;
            }
        }
        ans.push_back(last - beforeInd);
        return ans;
    }
    
};
