  
/*
 * 문제 : https://leetcode.com/problems/intersection-of-three-sorted-arrays/
 * 시간복잡도 : O()
 */

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int ind2 = 0;
        int ind3 = 0;
        int num = 0;
        for(int i=0;i<arr1.size();i++){
            num = arr1[i];
            
            while(ind2 < arr2.size() && arr2[ind2] < num) ind2++;
            if(ind2 >= arr2.size()) break;
            if(arr2[ind2] > num) continue;
            
            while(ind3 < arr3.size() && arr3[ind3] < num) ind3++;
            if(ind3 >= arr3.size()) break;
            if(arr3[ind3] > num) continue;
            
            ans.push_back(num);
        }
        return ans;
    }
};
