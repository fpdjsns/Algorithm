/**
 * problem : https://leetcode.com/problems/powerful-integers/
 * time complexity : O((logN bound) * (logM bound)) // N=x, M=y
 */
 
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> dict;
        for(int a = 1; a < bound; a *= x){
            for(int b = 1; b < bound; b *= y){
                if(a + b > bound) break;
                dict.insert(a + b);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        vector<int> answer;
        for(auto num: dict) {
            answer.push_back(num);
        }
        return answer;
    }
};
