/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
 * time complexity : O(N)
 */

#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& arr) {
    int ans = 0;
    for(int i=1; i<arr.size()-1;i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) 
            ans++;
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
