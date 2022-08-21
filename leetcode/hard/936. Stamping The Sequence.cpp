/**
 * problem : https://leetcode.com/problems/stamping-the-sequence/
 * time complexity : O(|target||stamp|)
 */
 
class Solution {
    char ANYTHING = '?';
    int findStampTarget(string& stamp, string& target) {
        for(int i=0; i<= target.size() - stamp.size(); i++){
            bool find = false;
            for(int j=0; j<stamp.size(); j++){
                if(target[i+j] == ANYTHING) continue;
                find = true;
                if(target[i+j] != stamp[j]) {
                    find = false;
                    break;
                }
            }
            if(find) return i;
        }
        return -1;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> answer;
        while(1) {
            int start = findStampTarget(stamp, target);
            if(start == -1) break;
            answer.push_back(start);
            for(int i=0; i<stamp.size(); i++){
                target[start+i] = ANYTHING;
            }
        }
        
        // check answer
        for(auto c: target) {
            if(c == ANYTHING) continue;
            return {};
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
