/**
 * problem : https://leetcode.com/problems/find-median-from-data-stream/
 * data structure : heap
 * time complexity : addNum - O(logN) / findMedian - O(1)
 */ 

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int cnt = 0;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        cnt % 2 == 0 ? maxHeap.push(num) : minHeap.push(num);
        cnt++;
        
        int left = maxHeap.empty() ? -1e9 : maxHeap.top();
        int right = minHeap.empty() ? 1e9 : minHeap.top();
        if(left > right) { // wrong sorting
            maxHeap.pop(); maxHeap.push(right);
            minHeap.pop(); minHeap.push(left);
        }
    }
    
    double findMedian() {
        int left = maxHeap.empty() ? 0 : maxHeap.top();
        int right = minHeap.empty() ? 0 : minHeap.top();
        // cout << left << ", " << right<< endl;
        if(cnt %2 == 0) return (double)(left + right) / 2;
        else return left;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
