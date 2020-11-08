/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/70130
 * time complexity : O(N) // N = |a|
 */

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int length = a.size();
    // numbers[number] = index list
    vector<vector<int>> numbers(length);
    for(int i=0;i<length;i++){
        numbers[a[i]].push_back(i);
    }
    
    int answer = 0;
    for(int num=0;num<length;num++){
        int left = 0;
        int cnt = 0;
        bool borrow = false;
        for(auto index: numbers[num]){
            if(borrow){
                if(left < index) cnt++; // possible
                left = left + 1;
                borrow = false;
            }
            
            if(left < index) { // use left
                cnt++;
                left = index + 1;
            } else { // borrow
                left = index + 1;
                borrow = true;
            }
        }
        if(borrow && left < length) cnt++; // possible
        answer = max(answer, 2*cnt);
    }
    return answer;
}
