/*
 * 문제 : https://algospot.com/judge/problem/read/LUNCHBOX
 * 시간복잡도 : O(NlogN)
 * 알고리즘 : Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> microwave, vector<int> eat){
    int N = microwave.size();
    vector<pair<int,int>> order(N);
    for(int i=0;i<N;i++){
        order[i] = {-eat[i],microwave[i]};
    }
    sort(order.begin(), order.end());
    int answer = 0;
    int eatTime = 0;
    for(int i=0;i<N;i++){
        int spendTime = order[i].second;
        answer += spendTime;
        eatTime -= spendTime;
        eatTime = max(eatTime, -order[i].first);
    }
    
    return answer + eatTime;
}

int main()
{
    int C;
    cin>> C;
    while(C--){
        int N;
        cin>> N;
        vector<int> microwave(N), eat(N);
        for(int i=0;i<N;i++) cin>>microwave[i];
        for(int i=0;i<N;i++) cin>>eat[i];
        cout<<solve(microwave, eat)<<endl;
    }

    return 0;
}
