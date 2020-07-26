/**
 * problem : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 * algorithm : binary search, Divide & Conquer
 * time complexity : 최적의 경우 O(logN). // #1 분기 타는게 없는 경우
 *                   최악의 경우 O(NlogN). // #1 분기를 자주 타는 경우
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        queue<pair<int,int>> q;
        q.push({0, nums.size()-1});
        int ans = nums[0];
        while(!q.empty()){
            int left = q.front().first;
            int right = q.front().second;
            q.pop();
            int m = (left+right)/2;
            ans = min(ans, nums[m]);
            if(left >= right) continue; // 범위 체크
            
            bool leftAsc = nums[m] > nums[left];
            bool rightAsc = nums[m] < nums[right];
            
            // #1
            // 가장 왼쪽 수와 m이 같거나, 가장 오른쪽 수와 m이 같은 경우
            // 내림차순, 오름차순을 제대로 판단할 수 없다. -> 모든 배열을 분할 정복 식으로 분리해서 탐색
            if((m != left && nums[m] == nums[left]) || (m != right && nums[m] == nums[right]) ||
              nums[left] == nums[right]){
                q.push({m+1, right});
                q.push({left, m-1});
            }
            
            // 오름차순
            else if(leftAsc && rightAsc) 
                q.push({left, m-1});
            
            // 작은수가 오른쪽 배열에 있음
            else if(leftAsc && !rightAsc) 
                q.push({m+1, right});
            
            // 작은수가 왼쪽 배열에 있음
            else if(!leftAsc && rightAsc) 
                q.push({left, m-1});
            
            // 내림차순
            else
                q.push({m+1, right});
        }
        return ans;
    }
};
