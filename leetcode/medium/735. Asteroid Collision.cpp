/**
 * problem : https://leetcode.com/problems/asteroid-collision/
 * time complexity : O(N) // N = |asteroids|
 * data structure : stack
 */

class Solution {
    bool isNeverCollide(int beforeSpeed, int speed) {
        // same direct or never collide
        return beforeSpeed * speed > 0 || speed > 0;
    }
    
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++){
            int speed = asteroids[i];
            int size = abs(speed);
            
            if(st.empty()){
                st.push(speed);
                continue;
            }
            
            int beforeSpeed = st.top();
            int beforeSize = abs(st.top());
            
            if(isNeverCollide(beforeSpeed, speed)) { 
                st.push(speed);
            }
            else{
                while(!st.empty()){
                    beforeSpeed = st.top();
                    beforeSize = abs(st.top());
                    if(isNeverCollide(beforeSpeed, speed)) break;
                    if(beforeSize <= size) st.pop(); // destroy st top
                    if(beforeSize >= size) break; // destroy astroids[i]
                }
                if(isNeverCollide(beforeSpeed, speed) || beforeSize < size) 
                    st.push(speed);
            }
            
        }
        
        // stack to vector
        vector<int> answer(st.size());
        int n = st.size();
        while(!st.empty()){
            answer[--n] = st.top();
            st.pop();
        }
        return answer;
    }
};
