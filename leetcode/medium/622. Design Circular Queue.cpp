/**
 * problem : https://leetcode.com/problems/design-circular-queue/
 * space complexity : O(k)
 */

class MyCircularQueue {
    vector<int> q;
    int left = 0;
    int right = -1;
    int cnt = 0;
    int size = 0;
public:
    MyCircularQueue(int k) {
        size = k;
        q = vector<int>(size);
        cnt = 0;
        left = 0;
        right = -1;
    }
    
    bool enQueue(int value) {
        if(cnt >= size) return false;
        right = (right + 1) % size;
        q[right] = value;
        cnt++;
        return true;
    }
    
    bool deQueue() {
        if(cnt <= 0) return false;
        left = (left + 1) % size;
        cnt--;
        return true;
        
    }
    
    int Front() {
        if(cnt == 0) return -1;
        return q[left];
    }
    
    int Rear() {
        if(cnt == 0) return -1;
        return q[right];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
