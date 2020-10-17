/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/68935
 * time complexity : O(log3N)
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string third;
    int tmp = n;
    while(tmp > 0) {
        third += tmp % 3;
        tmp /= 3;
    }
    int mul = 1;
    int answer = 0;
    for(int i=third.size()-1; i>=0; i--){
        answer += mul * third[i];
        mul *= 3;
    }
    
    return answer;
}
