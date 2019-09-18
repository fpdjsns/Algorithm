  
/*
 * codeground - Practice - SCPC 3회 예선 - 57. 괄호
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(N) // N = |S|
 */

#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

bool IsMatch(char a, char b)
{
	if (a == '(' && b == ')') return true;
	if (a == '{' && b == '}') return true;
	if (a == '[' && b == ']') return true;
	return false;
}

int solve()
{
	string s;
	cin >> s;
	int answer = 0;
	int now;

	//여는 괄호 인덱스 넣기. (()) 같이 안에 들어간 거 처리하기 위함
	stack<int> st;
	
	//올바른 문자열 시작하는 부분 인덱스
	//올바른 괄호 + 올바른 괄호 (연속된거 나올 때 처리하기 위함)
	int start_ind = -1;
	
	for (int i = 0; i < s.size(); i++)
	{
		now = s[i];

		//여는 괄호
		if (now == '(' || now == '[' || now == '{')
		{
			st.push(i);

			//새로운 올바른 괄호 시작부분이면 
			if (start_ind == -1)
				start_ind = i;//인덱스 갱신
		}
		else//닫는 괄호
		{
			if (!st.empty() && IsMatch(s[st.top()], now))//짝이 맞음
			{
				st.pop();
				if (st.empty())//올바른 괄호 + 올바른 괄호 처리 ex. ()()
					answer = max(answer, i - start_ind + 1);
				else //올바른 괄호안에 올바른 괄호인 경우 처리 ex. (())
					answer = max(answer, i - st.top());
			}
			else//짝이 안맞음
			{
				st = stack<int>();//스택 비워줌
				start_ind = -1;//올바른 괄호 시작인덱스 초기화
			}
		}
	}
	return answer;
}

int main(int argc, char** argv)
{
	int T, test_case;
	int Answer;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = solve();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
