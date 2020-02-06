/*
 * 문제 : https://leetcode.com/problems/smallest-string-with-swaps/
 * 시간복잡도 : O(NlogN)
 * 알고리즘 : Union Find
 */
 
class Solution {
    
    vector<int> p;

    int Find(int n)
    {
        if (p[n] == -1) return n;
        p[n] = Find(p[n]);
        return p[n];
    }

    //a, b 그룹 합치기
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
	    if (a != b)
            p[b] = a;//부모 트리 갱신
    }

public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int n = s.size();
		p = vector<int>(n, -1);
		for (int i = 0; i<pairs.size(); i++) {
			Union(pairs[i][0], pairs[i][1]);
		}

		// set map
		map<int, priority_queue<char, vector<char>, greater<char>>> m; // key : p[index], value : s[key]
		for (int i = 0; i<n; i++) {
			m[Find(i)].push(s[i]);
		}

		// set ans
		string ans = "";
		for (int i = 0; i<n; i++) {
			char now = m[Find(i)].top();
			m[Find(i)].pop();
			ans.push_back(now);
		}

		return ans;
	}

};
