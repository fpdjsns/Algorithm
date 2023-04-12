/**
 * problem : https://leetcode.com/problems/simplify-path/description/
 * time complexity : O(N)
 * data structure : stack
 */

class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string temp;

        stack<string> paths;
        while (getline(ss, temp, '/')) {
            cout << temp << endl;
            if(temp.size() == 0) continue;
            if(temp == ".") continue;
            if(temp == "..") {
                if(!paths.empty()) paths.pop();
                continue;
            }
            paths.push(temp);
        }
    
        string answer;
        while(!paths.empty()){
            string path = paths.top();
            paths.pop();
            answer = "/" + path + answer;
        }
        return answer.size() == 0 ? "/" : answer;
    }
};
