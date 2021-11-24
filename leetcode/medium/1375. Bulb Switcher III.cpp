/**
 * problem : https://leetcode.com/problems/bulb-switcher-iii/
 * time complexity : O(N) N = |light|
 */
 
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int answer = 0;
        int maxLight = -1;
        for(int i=0; i<light.size(); i++){
            maxLight = max(maxLight, light[i]);
            answer += (i+1 == maxLight);
        }
        return answer;
    }
};
