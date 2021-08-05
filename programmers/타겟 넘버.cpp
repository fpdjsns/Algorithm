/**
 * problem : 
 * time complexity : O(2^N)
 * algorithm : DFS
 */

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack<pair<int, int>> st; // ind, sum
    st.push({0, 0});
    while(!st.empty()) {
        int ind = st.top().first;
        int sum = st.top().second;
        st.pop();
        
        if(ind == numbers.size()) {
            if(sum == target) answer ++;
            continue;
        }
        
        st.push({ind+1, sum - numbers[ind]});
        st.push({ind+1, sum + numbers[ind]});
    }
    
    return answer;
}
