/*
 * 문제 : https://algospot.com/judge/problem/read/STRJOIN
 * 시간복잡도 : O(NlogN)
 * 알고리즘 : Greedy
 */

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solve(priority_queue<int, vector<int>> q){
    int answer = 0;
    int f, s, sum;
    while(q.size() > 1){
        f = q.top(); q.pop();
        s = q.top(); q.pop();
        sum = -(f + s);
        answer += sum;
        q.push(-sum);
    }
    return answer;
}

int main()
{
    int C;
    cin >> C;
    while(C--){
        int N;
        cin>> N;
        priority_queue<int, vector<int>> q;
        int tmp;
        for(int i=0;i<N;i++) {
            cin>>tmp;
            q.push(-tmp);
        }
        cout<<solve(q)<<endl;
    }

    return 0;
}
