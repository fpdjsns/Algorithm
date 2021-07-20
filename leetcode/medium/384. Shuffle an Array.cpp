/**
 * problem : https://leetcode.com/problems/shuffle-an-array/submissions/
 */
 
class Solution {
public:
    vector<int> origin;
    vector<int> arr;
    int n;
    
    Solution(vector<int>& nums) {
        n = nums.size();
        origin = nums;
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr = origin;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=0; i<n; i++){
            swap(arr[rand()%n], arr[i]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
