/**
 * problem : https://leetcode.com/problems/reduce-array-size-to-the-half/
 * time complexity : O(NlogN)
 */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> dict;
        for(auto num: arr) {
            dict[num]++;
        }
        vector<int> cnts(dict.size());
        for(auto now: dict) cnts.push_back(now.second);
        sort(cnts.begin(), cnts.end(), [](const int& a, const int& b){ return a > b; });
        int answer = 0;
        int cnt = 0;
        for(auto now: cnts){
            cnt += now;
            answer++;
            if(cnt >= n/2) break;
        }
        return answer;
    }
};
