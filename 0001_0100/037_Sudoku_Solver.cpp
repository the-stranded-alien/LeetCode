#include<bits/stdc++.h>

using namespace std;

#define int 				long long int
#define double				long double
#define F 					first
#define S 					second
#define pb 					push_back
#define pob					pop_back
#define mp 					make_pair
#define si 					set <int>
#define vi 					vector <int>
#define vs					vector <string>
#define vb					vector <bool>
#define pii 				pair <int, int>
#define vpi         		vector <pii>
#define vpp         		vector <pair <int, pii> >
#define vvi					vector <vector<int> >
#define mii         		map <int, int>
#define mpi         		map <pii, int>
#define spi         		set <pii>
#define nl					"\n"
#define tb					"\t"
#define sz(x)				((int) x.size())
#define all(p)				p.begin(), p.end()
#define maxQue				priority_queue <int>
#define minQue				priority_queue <int, vi, greater<int> >
#define bug(...)			__f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)			for(auto x : a) cout << x << " "; cout << endl
#define printRange(a,x,y)  	for(int i = x; i < y; i++) cout << a[i] << " "; cout << endl
#define printRev(a,x,y)		for(int i = x; i > y; i--) cout << a[i] << " "; cout << endl
#define printPair(p)      	for(auto x : p) cout << x.F << " " << x.S << endl; cout << endl
#define mod 				1e9 + 7

inline int power (int a, int b) {
	int x = 1;
	while (b) {
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

class Solution {
public:

	bool isSafe(vector<vector<char>>& board, int x, int y, int val) {
		for(int i = 0; i < board.size(); i++) {
			if((val == board[i][y] - '0') || (val == board[x][i] - '0')) return false;
		}
		int xs = (x / 3) * 3;
		int ys = (y / 3) * 3;
		for(int i = xs; i < (xs + 3); i++) {
			for(int j = ys; j < (ys + 3); j++) {
				if(val == board[i][j] - '0') return false;
			}
		}
		return true;		
	}

	bool solveSudokuHelper(vector<vector<char>>& board, int i, int j) {
		// Base Case
		if(i == 9) return true;
		// Recursive Case
		// 1. Jump to Next Row
		if(j == 9) return solveSudokuHelper(board, i + 1, 0);
		// 2. Skip the Pre-Filled Cells
		if(board[i][j] != '.') return solveSudokuHelper(board, i, j + 1);
		// 3. Try all Possibilities in the Cells to be Filled
		for(int num = 1; num <= 9; num++) {
			if(isSafe(board, i, j, num)) {
				board[i][j] = num + '0';
				bool solveSubProb = solveSudokuHelper(board, i, j + 1);
				if(solveSubProb) return true;
			}
		}
		// 4. Backtrack if No Options Work !
		board[i][j] = '.';
		return false;
	}

    void solveSudoku(vector<vector<char>>& board) {
		bool canBeSolved = solveSudokuHelper(board, 0, 0);
		if(!canBeSolved) cout << "Unsolveable Board Given\n";
		return;
    }
};

void solve() {
	// Main Code Goes Here !!
	vector<vector<char> > board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	Solution *soln = new Solution();
	soln->solveSudoku(board);
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << nl;
	}
}	

int32_t main() {
	// Fast Input-Output
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// Input-Output Files
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	freopen("../error.txt", "w", stderr);
#endif	

	clock_t startTime = clock();

	int testCases = 1;
	// cin >> testCases;
	while(testCases--) solve();

	cerr << "\nRun Time : " << ((double)(clock() - startTime) / CLOCKS_PER_SEC);

	return 0;
}