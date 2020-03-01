/**
 * [leetcode] 547. Friend Circles
 * problem : https://leetcode.com/problems/friend-circles/description/
 */

class Solution {
public:
    vector<int> p = vector<int>(201, -1);
    
    int find(int n){
        if(p[n] == -1)
            return n;
        return p[n] = find(p[n]);
    }
    
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b)
            p[b] = a;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        for(int i=0;i<M.size();i++){
            for(int j=i+1; j<M[i].size(); j++){
                if(M[i][j] == 1)
                    merge(i,j);
            }
        }
        int ans = 0;
        for(int i=0;i<M.size(); i++){
            cout<<i<<" "<<p[i]<<endl;
            if(p[i] == -1)
                ans++;
        }
        return ans;
    }
};
