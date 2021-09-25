/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/86051
 * time complexity : O(N)
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    vector<bool> exists(10, false);
    for(auto number: numbers) {
        exists[number] = true;
    }
    
    int answer = 0;
    for(int num = 0; num<exists.size(); num++){
        if(exists[num]) continue;
        answer += num;
    }
    return answer;
}
