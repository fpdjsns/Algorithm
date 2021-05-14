/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/77884
 * time complexity : O(NM). N = right-left+1, M = right 
 */

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int n = right-left+1;
    vector<int> cnts(n);
    for(int i = 1; i <= right; i++) {
        for(int j=left; j<=right; j++){
            if(j % i != 0) continue;
            cnts[j-left]++;
        }
    }
    
    int answer = 0;
    for(int i=left; i<=right; i++) {
        if(cnts[i-left] % 2 == 0) answer += i;
        else answer -= i;
    }
    
    return answer;
}
