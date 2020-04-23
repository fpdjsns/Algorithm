/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf
 * algorithm : binary search
 * time complexity : O(NlogM). N=n M = d
 */
 
#include<iostream>
#include<vector>

using namespace std;

long long int solve(const vector<long long int>& routes, long long int d){
    long long int left = 0;
    long long int right = d;
    
    long long int m = 0;
    while(left < right) {
        m = (left + right + 1) / 2;
        long long int day = m;
        for(int i=0;i<routes.size();i++){
            if(day % routes[i] > 0)
                day += routes[i] - (day % routes[i]);
        }
        if(day <= d) left = m; // possible
        else right = m-1;
    }
    return left;
}

int main() {
    int t;
    cin >> t;
    for(int tc = 1; tc<=t;tc++){
        int n;
        long long int d;
        cin>>n>>d;
        vector<long long int> routes(n);
        for(int i=0;i<n;i++) cin>>routes[i];
        printf("Case #%d: %lld\n", tc, solve(routes, d));
    }
    return 0;
}
