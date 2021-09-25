/** 
 * problem : https://leetcode.com/problems/break-a-palindrome/
 * time complexity : O(N/2)
 */

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        
        for(int i=0; i<n/2; i++){
            if(palindrome[i] == 'a') continue;
            palindrome[i] = 'a';
            return palindrome;
        }
        
        palindrome[n-1] = 'b';
        return palindrome;
    }
};
