/**
 * problem : https://programmers.co.kr/learn/courses/30/lessons/1845
 * data structure : set
 * time complexity : O(NlogN)
 */

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	set<int> s;
	for(int i=0;i<nums.size();i++)
		s.insert(nums[i]);
	answer = min(s.size(), nums.size() / 2);
	return answer;
}
