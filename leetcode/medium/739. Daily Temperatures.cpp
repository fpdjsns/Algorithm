/**
 * problem : https://leetcode.com/problems/daily-temperatures/
 * time complexity : O(N)
 * data structure : stack
 */
 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st; // (temp, index)
        vector<int> answer(n, 0);
        for(int i=n-1; i>=0; i--){
            int temp = temperatures[i];
            while(!st.empty()) {
                pair<int,int> ele = st.top();
                if(ele.first <= temp) {
                    st.pop();
                    continue;
                }
                break;
            }
            if(!st.empty()) answer[i] = st.top().second - i;
            st.push({temp, i});
        }
        return answer;
    }
};
