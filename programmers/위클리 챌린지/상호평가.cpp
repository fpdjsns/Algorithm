/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/83201
 * time complexity : O(N^2)
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char getGrade(int score) {
    if(score >= 90) return 'A';
    else if(score >= 80) return 'B';
    else if(score >= 70) return 'C';
    else if(score >= 50) return 'D';
    return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    int n = scores.size();
    
    for(int i=0; i<n; i++){
        pair<int, int> maxScore = {-1, 0}; // maxScore, cnt
        pair<int, int> minScore = {101, 0}; // minScore, cnt
        int sum = 0;
        for(int j=0; j<n; j++){
            int score = scores[j][i];
            sum += score;
            if(score > maxScore.first) {
                maxScore = {score, 1};
            } else if(score == maxScore.first) {
                maxScore.second++;
            }
            
            if(score < minScore.first) {
                minScore = {score, 1};
            } else if(score == minScore.first) {
                minScore.second++;
            }
        }
        
        char grade;
        if((scores[i][i] == maxScore.first && maxScore.second == 1) 
           || (scores[i][i] == minScore.first && minScore.second == 1)){
            sum -= scores[i][i];
            grade = getGrade(sum/(n-1));
        } else {
            grade = getGrade(sum/n);  
        }
        answer.push_back(grade);
    }
    return answer;
}
