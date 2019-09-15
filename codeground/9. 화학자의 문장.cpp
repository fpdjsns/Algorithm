/*
 * codeground - Practice - 연습문제 - 9. 화학자의 문장
 * 문제 : https://www.codeground.org/practice/practiceProblemList
 * 시간복잡도 : O(N)
 * 알고리즘 : DP
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define X 0
#define O 1
using namespace std;

string chemi[] = { "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
"No", "Lr" };

vector<vector<bool>> alph(26, vector<bool> (27, false));
string s;

//check[ind] : s[ind~] 만들 수 있는지 여부
vector<int> check;//-1: 방문 x. 0: 불가능. 1: 가능

bool go(int ind)
{
	if (ind == s.size())
		return true;

	int& ret = check[ind];
	if (ret == O)		return true;
	if (ret == X)		return false;

	int tmp = s[ind] - 'a';
	bool ans = false;

	if (alph[tmp][0])
		ans |= go(ind + 1);
	if (ind+1 < s.size() && alph[tmp][s[ind+1] - 'a' +1])
		ans |= go(ind + 2);

	if (ans) ret = O;
	else ret = X;

	return ans;
}

string solve()
{
	s.clear();
	cin >> s;
	check.clear(); check.resize(s.size(), -1);
	bool ans = go(0);
	if (ans)
		return "YES";
	else
		return "NO";
}

int main(int argc, char** argv)
{
	int T, test_case;
	int ind;
	for (auto s : chemi)
	{
		ind = s[0] - 'A';
		if (s.size() == 1)
			alph[ind][0] = true;
		else
			alph[ind][s[1] - 'a' + 1] = true;
	}
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		string Answer;
		Answer = solve();
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
