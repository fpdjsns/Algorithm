/**
 * problem : https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * time complexity : O(Nlogk)
 * algorithm : minHeap
 */
class KthLargest {
    // size is k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if(minHeap.empty() || minHeap.size() < k) {
            minHeap.push(val);
        } else if(val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        } 
        return minHeap.size() >= k ? minHeap.top() : 0;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
