/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/67258
 * time complexity : O(N). N = |gems|
 * algorithm : two-pointer
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> gemKinds;
    for(auto gem: gems) gemKinds.insert(gem);
    
    int n = gems.size();
    unordered_map<string, int> cnts;
    int left = 0;
    vector<int> answer = {1, n};
    set<string> exists;
    for(int right = 0; right < n; right++) {
        string gem = gems[right];
        cnts[gem]++;
        exists.insert(gem);
        while(left < right && cnts[gems[left]] > 1) {
            cnts[gems[left++]]--;
        }
        if(exists.size() == gemKinds.size() && right - left < answer[1] - answer[0]) 
            answer = {left+1, right+1};
    }
    return answer;
}
