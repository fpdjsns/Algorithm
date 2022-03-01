/**
 * problem : https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007549e5#analysis
 * time complexity : O(TNM), M = |Xi|
 */
 
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#define BIG 1
#define EQUAL 0
#define SMALL -1

using namespace std;

int compare(string a, string b){
    if(a.size() != b.size()) 
        return a.size() < b.size() ? SMALL : BIG;
    for(int i=0; i<a.size(); i++){
        if(a[i] == b[i]) continue;
        return a[i] < b[i] ? SMALL : BIG;
    }
    return EQUAL;
    
}

string add(string num, int addNum) {
    int carry = addNum;
    int n = num.size();
    for(int i=n-1; i>=0; i--){
        if(carry == 0) break;
        int tmp = (num[i] - '0') + carry;
        num[i] = (tmp % 10) + '0';
        carry = tmp / 10;
    }
    if(carry) num = (char)(carry + '0') + num;
    return num;
}

string getSetZeroBehind(string num, int cnt) {
    while(cnt--) num.append("0");
    return num;
}

string getPrefix(string num, int cnt) {
    return num.substr(0, cnt);
}

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N;
        cin >> N;
        vector<string> arr(N);
        for(int i=0; i<N; i++) cin >> arr[i];
        
        int answer = 0;
        for(int i=1; i<N; i++){
            string& now = arr[i]; string prev = arr[i-1];
            int len = now.size();
            int diff = prev.size() - len;
            
            if(compare(prev, now) == SMALL) { continue; }
            else if(diff == 0) { // same digit
                now = getSetZeroBehind(now, 1);
                answer++;
            } else { // prevLen > nowLen
                string prefixPrev = getPrefix(prev, len);
                answer += diff;
                int comp = compare(prefixPrev, now);
                if(comp == SMALL) {
                    now = getSetZeroBehind(now, diff);
                } // set 0
                else if(comp == EQUAL) { 
                    string tmp = add(prev, 1);
                    bool canAns = (compare(prefixPrev, getPrefix(tmp, len)) == EQUAL);
                    if(canAns) now = tmp; // set same prevNum & plus 1
                    else { // if can not than, add 1 digit
                        now = getSetZeroBehind(now, diff + 1);
                        answer++;
                    } 
                } else {
                    // add (diff + 1) digit
                    answer++;
                    now = getSetZeroBehind(now, diff + 1);
                }
            }
        }
        
        printf("Case #%d: %d\n", tc, answer);
    }
    return 0;
}
