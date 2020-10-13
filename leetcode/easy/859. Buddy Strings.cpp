/**
 * problem : https://leetcode.com/problems/buddy-strings/
 * time complexity : O(N) // N = |A|
 */
 
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        
        int size = A.size();
        int cnt = 0;
        int ind = 0;
        bool hasSameChar = false;
        vector<bool> check(26, false);
        
        for(int i=0;i<size;i++){
            if(check[A[i]-'a']) hasSameChar = true;
            check[A[i]-'a'] = true;
            
            if(A[i] == B[i]) continue;
            if(cnt == 0){
                ind = i;
            } else if(cnt == 1){
                if(A[ind] != B[i] || A[i] != B[ind])
                    return false;
            } else {
                return false;
            }
            cnt++;
        }
        
        return cnt == 2 || (cnt == 0 && hasSameChar);
    }
};
