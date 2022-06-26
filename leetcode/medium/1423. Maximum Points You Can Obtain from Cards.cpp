/**
 * problem : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * time complexity : O(k)
 * algorithm : subsum, sliding window
 */
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int answer = 0;
        int n = cardPoints.size();
        int leftSum = 0;
        for(int i=0; i<k; i++) leftSum += cardPoints[i];
        int rightSum = 0;
        for(int i=0; i<=k; i++) {
            answer = max(answer, leftSum + rightSum);
            rightSum += cardPoints[max(n-i-1, 0)];
            leftSum -= cardPoints[max(k-i-1, 0)];
        }
        return answer;
    }
};
