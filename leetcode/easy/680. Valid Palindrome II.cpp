/**
 * problem : https://leetcode.com/problems/valid-palindrome-ii/
 * time complexity : O(N)
 */
 
class Solution {
    bool validPalindrome(string s, bool deleteLeft) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        bool isDeleted = false;
        while(left < right) {
            if(s[left] == s[right]) {
                left++; right--;
                continue;
            }
            if(isDeleted) return false;
            isDeleted = true;
            if(deleteLeft){
                if(s[left+1] == s[right]) left++;
                else right--;
            } else {
                if(s[left] == s[right-1]) right--;
                else left++;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, true) || validPalindrome(s, false);
    }
};
