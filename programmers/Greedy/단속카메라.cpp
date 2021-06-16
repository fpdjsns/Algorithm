/** 
 * problem : https://programmers.co.kr/learn/courses/30/lessons/42884
 * time complexity : O(NlogN)
 * algorithm : greedy
 */
 
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int n = routes.size();
    sort(routes.begin(), routes.end());
    
    pair<int, int> cover = {-30001, -30001};
    int answer = 0;
    for(auto route: routes) {
        int s = route[0];
        int e = route[1];
        // impossible cover
        if(s > cover.second || e < cover.first ) {
            answer++;
            cover = {s , e};
        } else {
            cover = {max(cover.first, s), min(cover.second, e)};
        }
    }
    return answer;
}
