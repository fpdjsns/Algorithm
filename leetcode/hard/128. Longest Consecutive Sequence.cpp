/**
 * problem : https://leetcode.com/problems/longest-consecutive-sequence/
 * time complexity : O(N)
 * algorithm : union-find
 */

class Solution {
    
    unordered_map<int, int> cnt;
    unordered_map<int, int> p;
    int find(int num) {
        if(p.find(num) == p.end()) return num;
        return p[num] = find(p[num]);
    }
    
    // a <- b
    int merge(int a, int b) {
        a = find(a);
        b = find(b);
        
        if(a == b) return cnt[a];
        
        cnt[a] += cnt[b];
        p[b] = a;
        return cnt[a];
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        int answer = min(1, (int)nums.size());
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(cnt[num] > 0) continue;
            
            cnt[num] = 1;
            if(cnt[num-1] > 0)
                answer = max(answer, merge(num-1, num));
            if(cnt[num+1] > 0) 
                answer = max(answer, merge(num, num+1));
        }
        return answer;
    }
};
