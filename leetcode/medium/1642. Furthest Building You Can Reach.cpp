/** 
 * problem : https://leetcode.com/problems/furthest-building-you-can-reach/
 * time complexity : O(NlogN)
 * data structure : priority queue
 */
 
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        priority_queue<int> q;
        
        for(int i=1; i<heights.size(); i++) {
            int diff = heights[i] - heights[i-1];
            if(diff <= 0) continue;
            bricks -= diff;
            q.push(diff);
            if(bricks < 0) {
                if(ladders <= 0) 
                    return i-1;
                bricks += q.top(); 
                q.pop();
                ladders--;
            }
        }
        
        return n-1;
    }
};
