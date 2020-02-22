/**
 * problem: https://www.hackerrank.com/challenges/marcs-cakewalk/problem
 * time complexity: O(NlogN)
 */

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

long long solve(vector<int> arr) {
    int N = arr.size();
    long long ans = 0;

    // 내림차순 정렬
    sort(arr.begin(), arr.end(), [arr](int& a, int& b) { return a > b; });
    
    // 2^39 = 549,755,813,888‬ 
    // int 범위를 넘기때문에 long long
    long long multi = 1;
    for (int i = 0; i < N; i++) {
        ans += multi * arr[i];
        multi *= 2;
    }

    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    cout << solve(arr) << endl;
    return 0;
}
