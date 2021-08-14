/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/82612
 * time complexity : O(1)
 */

#include <algorithm>

using namespace std;

long long solution(int price, int money, int count) {
    long long sum = (long long)(count * (count + 1) / 2) * price;
    return max(0LL,  sum - money);
}
