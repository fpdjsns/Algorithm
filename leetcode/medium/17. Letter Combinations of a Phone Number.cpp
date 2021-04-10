/**
 * problem : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * algorithm : backtracking
 * time complexity : 4^N (N = |digits|)
 */
 
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        
        unordered_map<int, vector<char>> dict;
        dict['2'] = {'a', 'b', 'c'};
        dict['3'] = {'d', 'e', 'f'};
        dict['4'] = {'g', 'h', 'i'};
        dict['5'] = {'j', 'k', 'l'};
        dict['6'] = {'m', 'n', 'o'};
        dict['7'] = {'p', 'q', 'r', 's'};
        dict['8'] = {'t', 'u', 'v'};
        dict['9'] = {'w', 'x', 'y', 'z'};
        
        // backtracking
        vector<string> answer;
        queue<pair<int,string>> q;
        q.push({0, ""});
        int n = digits.size();
        
        while(!q.empty()){
            int ind = q.front().first;
            string str = q.front().second;
            q.pop();
            
            if(ind == n){
                answer.push_back(str);
                continue;
            }
            
            for(char c : dict[digits[ind]]) {
                str.push_back(c);
                q.push({ind + 1, str});
                str.pop_back();
            }
        }
        
        return answer;
    }
};
