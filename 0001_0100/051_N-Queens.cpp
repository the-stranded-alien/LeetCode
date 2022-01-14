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

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

class Solution {
public:
	bool canPlaceQueen(vector< vector<char> > &curBoard, int n, int x, int y) {
		// Column
		for(int k = 0; k < x; k++) {
			if(curBoard[k][y] == 'Q') return false;
		}
		// Left Diagonal
		int i = x;
		int j = y;
		while((i >= 0) && (j >= 0)) {
			if(curBoard[i][j] == 'Q') return false;
			i--;
			j--;
		}
		// Right Diagonal
		i = x;
		j = y;
		while((i >= 0) && (j < n)) {
			if(curBoard[i][j] == 'Q') return false;
			i--;
			j++;
		}
		return true;
	}

	bool solveNQueensHelper(int n, int i, vector<vector<string>> &allSoln, vector< vector<char> > &curBoard) {
		if(i == n) {
			vector<string> cur;
			for(int itr = 0; itr < n; itr++) {
				string row(curBoard[itr].begin(), curBoard[itr].end());
				cur.push_back(row);
			}
			allSoln.push_back(cur);
			return false; // false : For All Solutions
		}
		for(int j = 0; j < n; j++) {
			if(canPlaceQueen(curBoard, n, i, j)) {
				curBoard[i][j] = 'Q';
				bool canPlace = solveNQueensHelper(n, (i + 1), allSoln, curBoard);
				if(canPlace) return true;
				curBoard[i][j] = '.';
			}
		}
		return false;
	}

    vector<vector<string>> solveNQueens(int n) {
		vector< vector<string> > possibleSolutions;
		vector< vector<char> > curBoard(n, vector<char>(n, '.'));
		bool canPlace = solveNQueensHelper(n, 0, possibleSolutions, curBoard);
		return possibleSolutions;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	Solution *soln = new Solution();
	vector< vector<string> > allSoln = soln->solveNQueens(n);
	for(auto board : allSoln) {
		for(auto row : board) cout << row << nl;
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