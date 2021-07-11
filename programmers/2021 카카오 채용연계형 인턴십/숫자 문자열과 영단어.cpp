/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/81301
 * time complexity : O(N) N = |s|
 */
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, int> dict;
    dict["zero"] = 0;
    dict["one"] = 1;
    dict["two"] = 2;
    dict["three"] = 3;
    dict["four"] = 4;
    dict["five"] = 5;
    dict["six"] = 6;
    dict["seven"] = 7;
    dict["eight"] = 8;
    dict["nine"] = 9;
    
    
    int answer = 0;
    int ind = 0;
    while(ind < s.size()) {
        char c = s[ind];
        int num = 0;
        if(c >= '0' && c <= '9'){
            num = c - '0';
            ind++;
        } else {
            string tmp = "";
            while(ind < s.size() && s[ind] >= 'a' && s[ind] <= 'z' && dict.find(tmp) == dict.end()) tmp.push_back(s[ind++]);
            num = dict[tmp];
        }
        
        answer = 10*answer + num;
    }
    return answer;
}
