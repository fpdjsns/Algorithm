/**
 * problem : https://leetcode.com/problems/robot-bounded-in-circle/
 * time complexity : O(N)
 */

class Solution {
    int UP = 0;
    int RIGHT = 1;
    int DOWN = 2;
    int LEFT = 3;
public:
    bool isRobotBounded(string instructions) {
        int x = 0;
        int y = 0;
        int direct = UP;
        for(int i=0; i<4; i++){
            for(auto c: instructions){
                if(c == 'G'){
                    if(direct == UP) y++;
                    else if(direct == RIGHT) x++; 
                    else if(direct == DOWN) y--;
                    else if(direct == LEFT) x--;
                }
                else if(c == 'L') direct += 3;
                else if(c == 'R') direct++;
                direct %= 4;
            }
            if(x == 0 && y == 0) return true;
        }
        return false;
    }
};
