/**
 * problem : https://leetcode.com/problems/pancake-sorting/
 * time complexity : O(N^2)
 */
 
class Solution {
    vector<int> swap(vector<int>& A, int index) {
        for(int j=0; j < index/2 + 1; j++){
            int tmp = A[j];
            A[j] = A[index-j];
            A[index-j] = tmp;
        }
        return A;
    }
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        for(int i=0; i<A.size(); i++){
            int findNum = A.size() - i;
            int index = 0;
            for(int j=0; j<findNum; j++) {
                if(A[j] != findNum) continue;
                index = j;
                break;
            }
            if(index == findNum - 1) continue;
            if(index != 0){
                swap(A, index);
                ans.push_back(index + 1);
            }
            swap(A, findNum-1);
            ans.push_back(findNum);
        }
        return ans;
    }
};
