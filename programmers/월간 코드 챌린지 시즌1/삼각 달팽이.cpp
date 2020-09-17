/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/68645
 * time complexity : O(n^2 / 2)
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> solution(int n) {
   // queue
   // stack
   vector<queue<int>> q(n);
   vector<stack<int>> s(n);

   int num = 1;
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n - i; j++) {
         if (i % 3 == 1) { // queue
            q[(i / 3) * 2 + j].push(num++);
         }
         else if (i % 3 == 2) { // queue (default i)
            q[n - (i / 3) - 1].push(num++);
         }
         else { // stack
            s[n - (i / 3) - 1 -j].push(num++);
         }
      }
   }

   vector<int> answer;
   for (int i = 0; i<n; i++) {
      while (!q[i].empty()) {
         answer.push_back(q[i].front());
         q[i].pop();
      }
      while (!s[i].empty()) {
         answer.push_back(s[i].top());
         s[i].pop();
      }
   }
   return answer;
}
