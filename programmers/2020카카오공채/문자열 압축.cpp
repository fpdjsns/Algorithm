/*
 * programmers - 2020카카오공채 - 문자열 압축
 * 문제 : https://programmers.co.kr/learn/courses/30/lessons/60057
 * 시간복잡도 : O(N^2)
 */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int calculateLength(int len, int compression, int cnt){
    if(cnt == 1) return len + compression;
    while(cnt / 10 > 0){
        cnt /= 10;
        len++;
    }
    return len + compression + 1;
}

int solution(string s) {
    int length = s.size();
    int answer = length;
    
    for(int compression=1; compression <= length/2; compression++){ 
        int cnt = 1;
        int len = 0;
        string before = s.substr(0, compression);
        
        for(int i = compression; i + compression <= length; i+=compression){ 
            string now = s.substr(i, compression);
            if(before == now){
                cnt++;
            } else {
                len = calculateLength(len, compression, cnt);
                cnt = 1;
            }
            before = now;
        }
        len = calculateLength(len, compression, cnt);
        len += length % compression;
        answer = min(answer, len);
    }
    return answer;
}
