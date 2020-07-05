/**
 * problem : https://leetcode.com/problems/ugly-number-ii/
 * time complexity : O(3N)
 */
class Solution {
public:
    int nthUglyNumber(int n) {
      int ugly[3] = { 2, 3, 5 };
      set<long long> s;
      s.insert(1);
      long long ans = 1;
      for(int i = 0; i<n; i++){
        ans = *s.begin();
        s.erase(s.begin());
        
        for(int i=0; i<3; i++){
          s.insert(ans * ugly[i]);
        }
      }
      return ans;
    }
};
