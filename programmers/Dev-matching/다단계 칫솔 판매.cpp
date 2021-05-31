/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/77486
 * time complexity : O(N + M) // N = |enroll|, M = |seller|
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * enroll : 판매원 이름
 * referral : 다단계 조직에 참여시킨 판매원 이름
 * seller : 판매원 이름
 * amount : 판매량 집계 데이터의 판매 수량
 * 칫솔가격 : 100
 */
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    const int PRICE = 100;
    unordered_map<string, string> parentMap;
    for(int i=0; i<enroll.size(); i++)
        parentMap[enroll[i]] = referral[i];
    
    unordered_map<string, int> priceMap;
    for(int i=0; i<seller.size(); i++) {
        string people = seller[i];
        int price = amount[i] * PRICE;
        while(parentMap[people] != "-") {
            // 90% 
            priceMap[people] += price - (int)(price * 0.1);
            price *= 0.1;
            people = parentMap[people];
            if(price == 0) break;
        }
        priceMap[people] += price - (int)(price * 0.1);
    }
    
    vector<int> answer(enroll.size());
    for(int i=0; i<enroll.size(); i++)
        answer[i] = priceMap[enroll[i]];
    return answer;
}
