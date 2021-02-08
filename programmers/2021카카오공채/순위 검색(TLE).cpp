/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/72412
 */

#include <string>
#include <iostream>
#include <unordered_map>
#include <set>
// #include <algorithm>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;
using boost::algorithm::split;

vector<int> solution(vector<string> info, vector<string> queries) {
    // cpp, java, python
    unordered_map<string, set<int>> languageMap;
    // backend, frontend
    unordered_map<string, set<int>> positionMap;
    // junior, senior 
    unordered_map<string, set<int>> careerMap;
    // chicken, pizza
    unordered_map<string, set<int>> foodMap;
    
    unordered_map<int, int> scoreMap;
    
    for(int i = 0; i < info.size(); i++) {
        vector<string> infos;
        split(infos, info[i], boost::is_any_of(" "));
        
        languageMap[infos[0]].insert(i); 
        positionMap[infos[1]].insert(i); 
        careerMap[infos[2]].insert(i); 
        foodMap[infos[3]].insert(i); 
        scoreMap[i] = std::stoi(infos[4]);
    }
    
    vector<int> answer;
    
    for(string query: queries) {
        int answerCnt = 0;
        vector<string> conditions;
        split(conditions, query, boost::is_any_of(" "));
        
        int conditionCnt = 0;
        for(string condition: conditions){
            if(condition == "and") continue;
            if(condition == "-") continue;
            conditionCnt++;
        }
        
        string language = conditions[0];
        string position = conditions[2];
        string career = conditions[4];
        string food = conditions[6];
        int score = std::stoi(conditions[7]); 
        
        unordered_map<int, int> cntMap;
        // score
        for(auto people: scoreMap) if(people.second >= score) cntMap[people.first]++;
        if(language != "-") for(auto people : languageMap[language]) cntMap[people]++;
        if(position != "-") for(auto people : positionMap[position]) cntMap[people]++;
        if(career != "-") for(auto people : careerMap[career]) cntMap[people]++;
        if(food != "-") for(auto people : foodMap[food]) cntMap[people]++;
        
        for(auto now: cntMap) {
            int people = now.first;
            int cnt = now.second;
            if(cnt < conditionCnt) continue;
            answerCnt++;
        }
        answer.push_back(answerCnt);
    }
    
    return answer;
}
