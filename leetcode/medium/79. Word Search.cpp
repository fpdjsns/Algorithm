/*
 * problem : https://leetcode.com/problems/word-search/
 */

/**
 * algorithm : DFS, Backtracking
 * Runtime : 20ms
 * Memory : 9.1 MB
 */
class Solution {
	string word;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	bool find(vector<vector<char>>& board, int x,int y, int wordInd) {
		if (wordInd >= word.size()) return true;
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false; 
		if (board[x][y] != word[wordInd]) return false;

		char tmp = board[x][y];
		board[x][y] = ' ';
		bool ans = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			ans |= find(board, nx, ny, wordInd+1);
			if (ans) break;
		}
		board[x][y] = tmp;
		return ans;
	}

public:
	bool exist(vector<vector<char>>& board, string _word) {
		word = _word;
		if (board.size() == 0) return false;
		if (word.size() == 0) return true;
		bool ans = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (word[0] != board[i][j]) continue;
				ans |= find(board, i, j, 0);
				if (ans) break;
			}
			if (ans) break;
		}
		return ans;
	}
};

/**
 * algorithm : DFS
 * Runtime : 916ms
 * Memory : 432.3 MB
 */
class Solution {
	string word;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };

	bool find(vector<vector<char>> board, int x,int y, int wordInd) {
		if (wordInd >= word.size()) return true;
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false; 
		if (board[x][y] != word[wordInd]) return false;

		board[x][y] = ' ';
		bool ans = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			ans |= find(board, nx, ny, wordInd+1);
			if (ans) break;
		}
		return ans;
	}

public:
	bool exist(vector<vector<char>>& board, string _word) {
		word = _word;
		if (board.size() == 0) return false;
		if (word.size() == 0) return true;
		bool ans = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (word[0] != board[i][j]) continue;
				ans |= find(board, i, j, 0);
				if (ans) break;
			}
			if (ans) break;
		}
		return ans;
	}
};
