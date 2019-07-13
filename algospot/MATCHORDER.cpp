/*
 * 문제 : https://algospot.com/judge/problem/read/MATCHORDER
 * 시간복잡도 : O(NlogN)
 * 알고리즘 : Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> russian, vector<int> korean){
    int N = russian.size();
    int korInd = 0;
    int answer = 0;
    
    sort(russian.begin(), russian.end());
    sort(korean.begin(), korean.end());
    for(int i=0;i<N;i++){
        while(korInd < N && korean[korInd] < russian[i])
            korInd++;
        if(N <= korInd) break;
        korInd++;
        answer++;
    }
    return answer;
}

int main()
{
    int C;
    cin>> C;
    while(C--){
        int N;
        cin>> N;
        vector<int> russian(N), korean(N);
        for(int i=0;i<N;i++) cin>>russian[i];
        for(int i=0;i<N;i++) cin>>korean[i];
        cout<<solve(russian, korean)<<endl;
    }

    return 0;
}
