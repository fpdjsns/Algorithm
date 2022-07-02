/**
 * problem : https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 * time complexity : O(NlogN)
 * algorithm : greedy
 */
 
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int modulo = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = h;
        if(!horizontalCuts.empty())
            maxH = h - horizontalCuts[horizontalCuts.size()-1];
        int maxV = w;
        if(!verticalCuts.empty())
            maxV = w - verticalCuts[verticalCuts.size()-1];
        
        int before = 0;
        for(auto now: horizontalCuts) { maxH = max(maxH, now-before); before = now; };
        before = 0;
        for(auto now: verticalCuts) { maxV = max(maxV, now-before); before = now; };
        return (long long int)maxH * maxV % modulo;
    }
};
