/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/72412
 * algorithm : binary search
 * time complexity : O(NlogM) N = |query|, M = |info|
 */

#include <string>
#include <iostream>
#include <unordered_map>
#include <set>

#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;
using boost::algorithm::split;

vector<int> scoreMap[3][2][2][2];
void setInfos(string info);
int calcQuery(string query);

vector<int> solution(vector<string> infos, vector<string> queries) {
    
    for(auto info: infos) {
        setInfos(info);
    }
    
    // sorted
    for(int a=0; a<3; a++)
        for(int b=0; b<2; b++)
            for(int c=0; c<2; c++)
                for(int d=0; d<2; d++)
                    sort(scoreMap[a][b][c][d].begin(), scoreMap[a][b][c][d].end());
    
    vector<int> answer;
    for(string query: queries) {
        answer.push_back(calcQuery(query));
    }
    
    return answer;
}

vector<int> getIndexes(vector<string> infos) {
    
    int i1, i2, i3, i4;
    if(infos[0] == "cpp") i1 = 0; 
    else if(infos[0] == "java") i1 = 1;
    else if(infos[0] == "python") i1 = 2; 
    else i1 = -1;
    
    if(infos[1] == "backend") i2 = 0;
    else if(infos[1] == "frontend") i2 = 1; 
    else i2 = -1;
    
    if(infos[2] == "junior") i3 = 0;
    else if(infos[2] == "senior") i3 = 1; 
    else i3 = -1;
    
    if(infos[3] == "chicken") i4 = 0;
    else if(infos[3] == "pizza") i4 = 1; 
    else i4 = -1;
    
    return { i1, i2, i3, i4 };
}

void setInfos(string info) {
    vector<string> infos;
    split(infos, info, boost::is_any_of(" "));
    vector<int> inds = getIndexes(infos);
    scoreMap[inds[0]][inds[1]][inds[2]][inds[3]].push_back(std::stoi(infos[4]));
}

int calcQuery(string query) {
    vector<string> conditions;
    split(conditions, query, boost::is_any_of(" "));
        
    int conditionCnt = 0;
    for(string condition: conditions){
        if(condition == "and") continue;
        if(condition == "-") continue;
        conditionCnt++;
    }
    
    vector<int> inds = getIndexes({conditions[0], conditions[2], conditions[4], conditions[6]});
    int score = std::stoi(conditions[7]); 

    int cnt = 0;
    for(int a=0; a<3; a++) {
        if(inds[0] != -1 && inds[0] != a) continue;
        for(int b=0; b<2; b++) {        
            if(inds[1] != -1 && inds[1] != b) continue;
            for(int c=0; c<2; c++) {        
                if(inds[2] != -1 && inds[2] != c) continue;
                for(int d=0; d<2; d++){        
                   if(inds[3] != -1 && inds[3] != d) continue;
                    vector<int>& scores = scoreMap[a][b][c][d];
                     // binary search
                    cnt += (int)scores.size() - (lower_bound(scores.begin(), scores.end(), score) - scores.begin());
                }
            }
        }
    }
    
    return cnt;
}
