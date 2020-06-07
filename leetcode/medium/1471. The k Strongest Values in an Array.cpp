/**
 * problem : https://leetcode.com/problems/the-k-strongest-values-in-an-array/
 * time complexity : O(NlogN)
 * algorithm : sort
 */

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> tmpArr = arr;
        sort(tmpArr.begin(), tmpArr.end());
        int median = tmpArr[(arr.size()-1)/2];
        
        sort(arr.begin(), arr.end(), [median](int& a, int& b) {
            if(a == b) return false;
            int tmpA = a - median;
            if(tmpA<0) tmpA = -tmpA;
            int tmpB = b - median;
            if(tmpB<0) tmpB = -tmpB;
            if(tmpA == tmpB)
                return a > b;
            return tmpA >= tmpB;
        });
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};
