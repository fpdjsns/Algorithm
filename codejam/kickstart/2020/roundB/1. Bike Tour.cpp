/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
 * time complexity : O(N)
 */

#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& arr) {
    int ans = 0;
    bool asc = false;
    for(int i=1;i<arr.size();i++){
        if(arr[i] == arr[i-1]) {
            asc = false;
        } else if(arr[i] < arr[i-1]){
            if(asc) ans++;
            asc = false;
        } else {
            asc = true;
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        printf("Case #%d: %d\n", tc, solve(arr));
    }
    return 0;
}
