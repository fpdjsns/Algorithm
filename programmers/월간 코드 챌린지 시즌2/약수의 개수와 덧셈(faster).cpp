
/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/77884
 * time complexity : O(logN). N = right
 */


#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = (right - left + 1) * (left + right) / 2;
    for(int i=1; i<=right; i++){
        if(i*i < left) continue;
        if(i*i > right) break;
        answer -= 2 * i * i;
    }
    
    return answer;
}
