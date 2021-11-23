/**
 * problem : https://leetcode.com/problems/largest-component-size-by-common-factor/
 * algorithm : union-find
 * time complexity : O(NlogM)
 */
 
class Solution {
    vector<int> parents;
    int find(int n) {
        if(parents[n] == -1) 
            return n;
        return parents[n] = find(parents[n]);
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        parents[a] = b;
        return true;
    }
    
public:
    int largestComponentSize(vector<int>& nums) {
        int maxNum = nums[0];
        for(auto num: nums) {
            maxNum = max(maxNum, num);
        }
        parents = vector<int>(maxNum + 1, -1);
    
        for(auto num: nums) {
            for(int i=2; i<=(int)sqrt(num + 1); i++){
                if(num % i != 0) continue;
                merge(num, i);
                merge(num, num / i);
            }
        }
            
        int answer = 0;
        unordered_map<int, int> cnts;
        for(auto num: nums){
            int parent = find(num);
            cnts[parent]++;
            
            answer = max(answer, cnts[parent]);
        }
        
        return answer;
    }
};
