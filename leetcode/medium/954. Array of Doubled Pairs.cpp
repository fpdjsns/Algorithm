/**
 * problem : https://leetcode.com/problems/array-of-doubled-pairs/
 * time complexity : O(NlogN)
 */
 
class Solution {
    
    static bool compare(int& a, int& b){
        return (long long)a*a < (long long)b*b;
    }
    
public:
    
    bool canReorderDoubled(vector<int>& A) {
       
        // num, cnt
        map<int,int> m;
        vector<int> arr;
        for(int i=0;i<A.size();i++){
            m[A[i]]++;
            arr.push_back(A[i]);
        }
        
        sort(arr.begin(), arr.end(), compare);
        
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]] == 0) continue;
            
            int findNum = arr[i]*2;
            int findCnt = m[findNum];
            
            int needCnt = (findNum == 0 ? 2 : 1);
            if(findCnt < needCnt) {
                return false;
            }
            
            if(findNum != 0)
                m[arr[i]]--;
            m[findNum] -= needCnt;
        }
        
        return true;
    }
};
