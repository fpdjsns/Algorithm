/**
 * problem : https://leetcode.com/problems/largest-rectangle-in-histogram/
 * time complexity : O(N)
 */

class Solution {
    void setArray(vector<int> heights, int index, stack<int>& st, vector<int>& array) {
        while(!st.empty() && heights[index] < heights[st.top()]) {
            // possible
            array[st.top()] = index;
            st.pop();
        }
        st.push(index);
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        vector<int> leftArray(N, -1);
        vector<int> rightArray(N, N);
        
        stack<int> st;
        for(int i=0;i<N;i++)
            setArray(heights, i, st, rightArray);
        
        for(int i=N-1; i>=0; i--)
            setArray(heights, i, st, leftArray);
        
        int answer = 0;
        for(int i=0; i<N; i++){
            answer = max(answer, heights[i] * (rightArray[i] - leftArray[i] - 1));
        }
        return answer;
    }
};
