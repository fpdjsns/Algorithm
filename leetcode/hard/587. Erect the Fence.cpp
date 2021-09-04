/**
 * problem : https://leetcode.com/problems/erect-the-fence/
 * time complexity : O(NlogN)
 * algorithm..? : 볼록 껍질(Convex Hull)
 */
class Solution {
    
public:
    class Tree {
    public:
        int x;
        int y;
        float angl; // 각도
        int dist = 0;
        
        void setDist(Tree other) {
            this->dist = pow(this->x - other.x, 2) + pow(this->y - other.y, 2);
        }
    };
    
    int ccw(Tree a, Tree b, Tree c) {
        int tmp = a.x*b.y + b.x*c.y + c.x*a.y;
        tmp -= a.y*b.x + b.y*c.x + c.y*a.x;
        if(tmp > 0) return 1; // 반시계
        else if (tmp < 0) return -1; // 시계
        else return 0; // 평행
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& originTrees) {
        int n = originTrees.size();
        
        // x 오름차순 정렬(x 같으면 y 오름차순)
        sort(originTrees.begin(), originTrees.end());
        
        Tree firstTree = {originTrees[0][0], originTrees[0][1], 0};
        vector<Tree> trees(n-1);
        
        for(int i=1; i<n; i++) {
            int x = originTrees[i][0];
            int y = originTrees[i][1];
            trees[i-1] = {x, y, (float)atan2(y - firstTree.y, x - firstTree.x)};
            trees[i-1].setDist(firstTree);
        }
        sort(trees.begin(), trees.end(), [](const Tree& a, const Tree& b) { 
            if(a.angl == b.angl) { // 각도가 같은 경우
                if(a.angl <= 0) return a.dist< b.dist; // 각도가 음수면 거리가 가까운 순
                else return a.dist > b.dist; // 평행이거나 각도가 양수면 거리가 먼 순
            }
            return a.angl < b.angl; 
        });
    
        trees.push_back(firstTree); // #1 계산쉽게 첫번째 트리 한 번 더 넣어줌
        vector<Tree> answer = {
            {firstTree.x, firstTree.y},
            {trees[0].x, trees[0].y}
        };
        for(int i=1; i<trees.size(); i++){
            Tree c = trees[i];
            while(answer.size() >= 2) { // 최소 2개는 있어야 함
                Tree a = answer[answer.size()-2];
                Tree b = answer[answer.size()-1];
                
                if(ccw(a, b, c) < 0) { // 시계방향 = 중간 점 빼야 됨
                    answer.pop_back(); // b제거
                } else {
                    break;
                }
            }
            answer.push_back(c);
        }
        answer.pop_back(); // #1에서 중복 트리 한 번 더 넣었으니까 한 번 빼줌
        
        // for(auto tree: trees) {
        //     cout << tree.x << " " << tree.y << " " << tree.angl << endl;
        // }
        
        vector<vector<int>> vectorAnswer;
        for(auto tree: answer) {
            vectorAnswer.push_back({tree.x, tree.y});
        }
        return vectorAnswer;
                                
    }
};
