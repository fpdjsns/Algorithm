/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/70129
 * time complexity : O((logN)^2)
 */
 
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string changeBinary(int num) {
    string binary;
    while(num > 0) {
        binary.push_back((num % 2) + '0');
        num /= 2;
    }
    return binary;
}

vector<int> solution(string s) {
    int cnt = 0;
    int zeroCnt = 0;
    while(s.size() != 1) {
        cnt++;
        int tmpCnt = 0;
        for(int i=0;i<s.size();i++){
            tmpCnt += s[i] == '0';
        }
        zeroCnt += tmpCnt;
        s = changeBinary(s.size() - tmpCnt);
    }
    return vector<int> { cnt, zeroCnt };
}
