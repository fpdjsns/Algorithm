/*
 * 문제 : https://leetcode.com/problems/dinner-plate-stacks/
 * 시간복잡도 : push - O(1), O(N)(stack모두 찰 때) / pop - O(1), O(N)(null일 때) / popAtStack - O(logN), O(N)(null일 때)
 * 자료구조 : Stack, Set, Map
 */

class DinnerPlates {
private:
    int capacity = 0;
    set<int> fullStack; // 가득찬 스택 인덱스
    set<int> blankFullStack; // fullStack의 사이사이에 비어있는 index. push시에 바로 찾아가기 위함
    map<int, stack<int>> stackMap; // {index, stack}
    
    // O(N)
    void deleteIfNullStack(int index) {
        map<int, stack<int>>::iterator it = stackMap.find(index);
        if(it == stackMap.end()) return;
        
        // last stack이 fullStack에 포함이 되었으면 fullStack에서 삭제
        if(fullStack.find(it->first) != fullStack.end()){
            fullStack.erase(it->first);
        }
        
        // last stack size가 0이면 map에서 삭제
        if((it->second).empty()){
            stackMap.erase(it);
        }
        
        // fullStack 사이에 낀 index라면 blankFullStack에 갱신
        if(!fullStack.empty() && index < *(fullStack.rbegin())) {
            blankFullStack.insert(index);
        }
    }
    
public:
    
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        
        // 처음 push하는 경우
        int index = 0;
        
        if(!blankFullStack.empty()){ // 가득찬 스택들 중간에 빈 곳이 있는 경우
            index = *(blankFullStack.begin()); // 빈 곳 중 가장 왼쪽에 넣어준다.
        } else if(!fullStack.empty()){ // 모두 가득 찬 스택밖에 없는 경우 fullStack의 가장 큰 수 + 1에 넣음
            index = *(fullStack.rbegin()) + 1;
        }
        
        stackMap[index].push(val); // index 스택에 val를 push한다.
        if((int)stackMap[index].size() == capacity) { // stack이 가득 찬 경우
            fullStack.insert(index); // fullStack에 넣고
            blankFullStack.erase(index); // blankFullStack엔 뺀다.
        }
    }
    
    int pop() {
        // stackMap 없으면 -> -1 리턴
        if(stackMap.empty())
            return -1;
        
        // stackMap이 있으면 가장 오른쪽 스택(last stack) pop
        int index = stackMap.rbegin()->first;
        int answer = stackMap[index].top(); stackMap[index].pop();
            
        deleteIfNullStack(index);
        return answer;
    }
    
    int popAtStack(int index) {
        // stackMap[index] 없으면 -1
        if(stackMap.find(index) == stackMap.end())
            return -1;
        
        int answer = stackMap[index].top(); stackMap[index].pop();
        deleteIfNullStack(index);
        
        return answer;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
