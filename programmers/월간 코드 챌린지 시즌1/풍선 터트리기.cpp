/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/68646
 * time complexity : O(N)
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
   int size = a.size();
   vector<int> leftMin(size);
   vector<int> rightMin(size);
   leftMin[0] = a[0];
   rightMin[a.size() - 1] = a[size - 1];
   for (int i = 0; i<size; i++) {
      leftMin[i] = min(a[i], leftMin[max(0, i - 1)]);
   }
   for (int i = a.size() - 1; i >= 0; i--) {
      rightMin[i] = min(a[i], rightMin[min(size - 1, i + 1)]);
   }

   int answer = 0;
   for (int i = 0; i<a.size(); i++) {
      int tmp = 0;
      int now = a[i];
      tmp += leftMin[max(0, i - 1)] < now;
      tmp += rightMin[min(size - 1, i + 1)] < now;
      if (tmp < 2) answer++;
   }

   return answer;
}
