/**
 * problem : https://leetcode.com/problems/accounts-merge/
 * time complexity : O(NM). N = |accounts|, M = |accounts[i]|
 * algorithm : union-find
 */
 
class Solution {
    vector<int> parents;
    unordered_map<string, int> indexes;
    unordered_map<string, int> emailIndexes; // key = email, value = index
    
    int find(int index) {
        if(parents[index] == -1 || parents[index] == index) return index;
        return parents[index] = find(parents[index]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        parents[b] = a;
    }
    
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parents = vector<int>(n, -1);
        for(int i=0; i<n; i++){
            indexes[accounts[i][0]] = i;
        }
        for(int j=0; j<n; j++){
            string name = accounts[j][0];
            for(int i=1; i<accounts[j].size(); i++){
                string email = accounts[j][i];
                if(emailIndexes.find(email) != emailIndexes.end()) {
                    merge(emailIndexes[email], j);
                } else {
                    emailIndexes[email] = j;
                }
            }
        }
        
        map<int, set<string>> tmpAnswer;
        for(int i=0; i<n; i++) {
            int nameIndex = find(i);
            for(int j=1; j<accounts[i].size(); j++){
                tmpAnswer[nameIndex].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> answer;
        for(auto tmp: tmpAnswer) {
            answer.push_back({accounts[tmp.first][0]});
            for(auto email: tmp.second) {
                answer.back().push_back(email);
            }
        }
        
        
        return answer;
    }
};
