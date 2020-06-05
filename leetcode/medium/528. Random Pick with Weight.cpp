/**
 * problem : https://leetcode.com/problems/random-pick-with-weight/
 * time complexity : O(logN)
 */

class Solution {
    vector<int> arr;
    int sum = 0;
public:
    Solution(vector<int>& w) {
        arr = vector<int>(w.size());
        for(int i=0;i<w.size();i++){
            sum += w[i];
            arr[i] = sum; 
        }
    }
    
    int pickIndex() {
        int random = rand() % sum;
        return upper_bound(arr.begin(), arr.end(), random) - arr.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
