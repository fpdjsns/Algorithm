/**
 * problem : https://www.acmicpc.net/problem/17143
 * time complexity : O(N^2 * M)) (// let, N = R, C)
 */

#include <iostream>
#include <map>

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

using namespace std;

int R, C, M;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

class Shark {
public:
    int speed;
    int direction;
    int size;
    
    pair<int,int> moveNext(int x, int y) {
        
        int modular = 0;
        switch(direction){
            case UP: case DOWN:
              modular = 2 * (R-1);
              break;
            case RIGHT: case LEFT:
              modular = 2 * (C-1);
             break;
        }
        
        for(int i=0; i<(speed % modular); i++){
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                switch(direction){
                    case UP: direction = DOWN; break;
                    case DOWN: direction = UP; break;
                    case RIGHT: direction = LEFT; break;
                    case LEFT: direction = RIGHT; break;
                    defalt: break;
                }
                nx = x + dx[direction];
                ny = y + dy[direction];
            }
            x = nx; y = ny;
        }
        return {x, y};
    }
};

int main(){
    cin >> R >> C >> M;
    
    map<pair<int,int>, Shark> sharks;
    
    int r, c, s, d, z;
    for(int i=0;i<M;i++){
        cin >> r >> c >> s >> d >> z;
        sharks[{r-1,c-1}] = Shark{s, d, z};
    }
    
    int answer = 0;
    for(int column = 0; column < C; column++){
        for(int row = 0; row < R; row++){
            if(sharks.find({row, column}) != sharks.end()){
                answer += sharks[{row, column}].size;
                sharks.erase({row, column});
                break;
            }
        }
        
        map<pair<int,int>, Shark> nextSharks;
        for(map<pair<int,int>, Shark>::iterator it = sharks.begin();
            it != sharks.end(); it++){
            pair<int, int> now = it->first;
            Shark shark = it->second;
            pair<int, int> next = shark.moveNext(now.first, now.second);
            if(nextSharks.find(next) != nextSharks.end()){
                if(nextSharks[next].size < shark.size) { nextSharks.erase(next); nextSharks[next] = shark; }
            } else { nextSharks[next] = shark; }
        }
        sharks = nextSharks;
    }
    
    cout << answer << endl;
    
    return 0;
}
