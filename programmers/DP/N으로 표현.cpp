/** 
 * problem : https://programmers.co.kr/learn/courses/30/lessons/42895
 * algorithm : DP
 */

#include <string>
#include <vector>
#include <set>
#define MAX_CNT 8

using namespace std;

// dp[i] = N을 i번 써서 만들 수 있는 수들의 집합
vector<set<int>> dp;
set<int> solve(int N, int cnt) {
    set<int>& ret = dp[cnt];
    if(ret.size() != 0) return ret;
    
    // N
    int tmp = 0;
    for(int i=0;i<cnt; i++){
        tmp = tmp * 10 + N;
    }
    ret.insert(tmp);
    
    for(int i=1; i < cnt; i++){
        for(auto num1: solve(N, i)){
            for(auto num2: solve(N, cnt - i)){
                // plus 
                ret.insert(num1 + num2);
                // minus
                ret.insert((abs)(num1 - num2));
                // multiple
                ret.insert(num1 * num2);
                // divide
                if(num2 != 0) ret.insert(num1 / num2);
                if(num1 != 0) ret.insert(num2 / num1);
            }
        }
    }
    
    return ret;
}

int solution(int N, int number) {
    dp = vector<set<int>>(MAX_CNT + 1);
    solve(N, MAX_CNT);
    for(int i=1; i<=MAX_CNT; i++){
        if(dp[i].find(number) != dp[i].end()) 
            return i;
    }
    return -1;
}
