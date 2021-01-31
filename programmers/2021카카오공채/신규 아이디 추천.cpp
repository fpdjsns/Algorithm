/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/72410
 * time complexity : O(N). N = |new_id|
 */
 
#include <string>
#include <vector>

using namespace std;

char COMMA = '.';

string solution(string new_id) {
    string answer = "";
    for(char c: new_id) {
        
        // #6
        if(answer.size() == 15) break;
        
        // #1
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        
        // #2
        if(!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
          || c == '-' || c == '_' || c == COMMA)) continue;
        
        // #4
        if(c == COMMA 
           && (answer.size() == 0 || answer.back() == COMMA)) 
            continue;
        
        answer.push_back(c);
    }
    
    // #4
    if(answer.back() == COMMA) answer.pop_back();
    // #5
    if(answer.size() == 0) answer = "a";
    // #7
    while(answer.size() <= 2) answer.push_back(answer.back());
    
    return answer;
}
