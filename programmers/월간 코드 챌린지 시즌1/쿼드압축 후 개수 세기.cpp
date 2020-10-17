/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/68936
 * time complexity : O(Nlog4(N))
 * algorithm : divide & conquer
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sum;
int N;
vector<int> answer;

void go(vector<vector<int>>& arr, int sx, int ex, int sy, int ey) {
   int n = ex - sx;
   int num = arr[sx][sy];
   if (n == 1) {
      answer[num]++;
      return;
   }

   bool canMerge = true;
   for (int i = sx; i<ex; i++) {
      for (int j = sy; j < ey; j++) {
         if (arr[i][j] == num) continue;
         canMerge = false;
         break;
      }
      if (!canMerge) break;
   }

   if (canMerge) {
      answer[num]++;
      return;
   }

   go(arr, sx, ex - n/2, sy, ey - n/2);
   go(arr, sx + n/2, ex, sy, ey - n/2);
   go(arr, sx, ex - n/2, sy + n/2, ey);
   go(arr, sx + n/2, ex, sy + n/2, ey);
}

vector<int> solution(vector<vector<int>> arr) {
   N = arr.size();
   sum = vector<vector<int>>(N, vector<int>(N, 0));
   for (int i = 0; i<N; i++) {
      for (int j = 0; j<N; j++) {
         sum[i][j] = sum[i][max(0, j - 1)] + arr[i][j];
      }
   }

   answer = vector<int>(2, 0);
   go(arr, 0, N, 0, N);
   return answer;
}
