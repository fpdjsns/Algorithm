/*
 * 문제 : https://leetcode.com/problems/unique-number-of-occurrences/
 * 시간복잡도 : O(NlogN)
 * 자료구조 : set, map
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size = arr.size();
        set<int> s;
        map<int, int> cnt; // cnt[num] = num이 나온 횟수
        map<int, int> num; // num[cnt[num]] = cnt[num]이 될 수 있는 num의 개수
        int uniqueNumCnt = 0;
        for(int i=0;i<size;i++){
            int tmp = cnt[arr[i]]++;
            s.insert(arr[i]);
            if(tmp > 0) {
                uniqueNumCnt -= (num[tmp] == 1);
                num[tmp]--;
                uniqueNumCnt += (num[tmp] == 1);
            }
            uniqueNumCnt -= (num[tmp+1] == 1);
            num[tmp+1]++;
            uniqueNumCnt += (num[tmp+1] == 1);
        }
        return uniqueNumCnt == s.size();
    }
};
