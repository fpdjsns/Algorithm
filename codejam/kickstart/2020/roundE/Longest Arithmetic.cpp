/**
 * problem : https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed
 * time complexity : O(N)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int C;
    cin >> C;
    for(int tc = 1; tc <= C; tc++){
        int N; cin >> N;
        vector<int> arr(N); 
        for(int i=0;i<N;i++) cin>>arr[i];
        int ans = 0;
        int cnt = 0;
        int diff = 0;
        for(int i=0;i<N;i++){
            int now = arr[i];
            int before = i == 0 ? arr[i] : arr[i-1];
            if (diff == now - before) cnt++;
            else cnt = 1 + (i > 0);
            diff = now - before;
            ans = max(ans, cnt);
        }
        cout << "Case #" << tc<<": "<<ans<<endl;
    }
    return 0;
}
