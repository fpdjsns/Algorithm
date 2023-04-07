/**
 * problem : https://leetcode.com/problems/boats-to-save-people/description/
 * time complexity : O(N)
 * algorithm : two pointer
 */
 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0; int right = people.size()-1;
        int answer = 0;
        while(left < right) {
            if(people[right] + people[left] <= limit) {
                left++; 
            }
            right--;
            answer++;
        }
        return answer + (left == right);
    }
};
