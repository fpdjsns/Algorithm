/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/77885
 * time complexity : O(N). N = |numbers|
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    int n = numbers.size();
    vector<long long> answer(n);
    for(int i=0; i<n; i++){
        long long number = numbers[i];
        if(number % 2 == 0) {
            answer[i] = number + 1;
        } else {
            // 최하위 비트
            unsigned long long lastBit = ~number & (number + 1); 
            answer[i] = (number | lastBit) & ~(lastBit >> 1);
        }
    }
    return answer;
}
