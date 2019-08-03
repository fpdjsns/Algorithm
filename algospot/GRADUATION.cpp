/*
 * 문제 : https://algospot.com/judge/problem/read/GRADUATION
 * 시간복잡도 : O(M * 2^(N+C))
 * 알고리즘 : Bitmask
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
#define inf 1e9

using namespace std;

int N, K, M, L; 
vector<vector<int>> dp; // dp[classes] = classes들을 수강했을 때 정답이 될 수 있는 남은 최소 학기
vector<int> classList; // classList[sem] = sem 학기에 들을 수 있는 클래스들
vector<int> preClassList; // preClassList[class] = class를 듣기위한 선수과목

int getCnt(int n) {
    if(n == 0) return 0;
    return n % 2 + getCnt(n / 2);
}

// sem : 현재 탐색할 학기
// classes : 현재까지 수강한 수업
// classCnt : 현재까지 수강한 수업의 수
int solve(int sem, int classes) {
    if(K <= getCnt(classes)){
      return 0; // don't need to take any more classes
    } 
    if(M <= sem) return inf; // don't have any classes (can't be answer) 
    
    int& ret = dp[sem][classes];
    if(ret != -1) return ret;
    ret = solve(sem + 1, classes); // not take the any class in sem

    int canTake = classList[sem] & ~classes;
    
    // 들을 수 없는 것 제외
    for(int i=0;i<N;i++){
        int now = 1 << i;
        if(!(canTake & now)) continue; // take now class not yet
        if((preClassList[i] & classes) == preClassList[i]) continue; // can take now class because of satisfied prerequisites
        canTake &= ~now;
    }
    
    // 모든 부분집합 탐색
    for(int now = canTake; 0 < now; now = ((now-1) & canTake)){
        if(L < getCnt(now)) continue;
        ret = min(ret, 1 + solve(sem + 1, classes | now));
    }
    
    return ret;
}

int main()
{
    int C;
    cin >> C;
    while(C--) {
        cin >> N >> K >> M >> L;
        
        dp = vector<vector<int>>(M, vector<int>(1 << N, -1));
        
        int tmp, cnt;
        preClassList = vector<int>(N, 0);
        for(int i=0;i<N;i++){
            cin >> cnt;
            for(int j=0;j<cnt;j++){
                cin >> tmp;
                preClassList[i] |= (1 << tmp);
            }
        }
        classList = vector<int>(M, 0);
        for(int i=0;i<M;i++){
            cin >> cnt;
            for(int j=0;j<cnt;j++){
                cin >> tmp;
                classList[i] |= (1 << tmp);
            }
        }
        
        int ans = solve(0, 0);
        if(ans == inf)
            cout << "IMPOSSIBLE"<< endl;
        else 
            cout << ans << endl;
    }
    
    return 0;
}
