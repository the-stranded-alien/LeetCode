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

// You are given an m x n grid where each cell
// can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent
// to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no
// cell has a fresh orange. If this is impossible, return -1.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int> > rottenOranges;
        int freshOranges = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        for(int i = 0; i < nr; i++) {
        	for(int j = 0; j < nc; j++) {
        		if(grid[i][j] == 2) rottenOranges.push(make_pair(i, j));
        		else if(grid[i][j] == 1) freshOranges++;
        	}
        }
        // Init Element
        rottenOranges.push(make_pair(-1, -1));
        int time = -1;
        vector<pair<int, int> > directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while(!rottenOranges.empty()) {
        	pair<int, int> fr = rottenOranges.front();
        	rottenOranges.pop();
        	int row = fr.first;
        	int col = fr.second;
        	if(row == -1) {
        		time++;
        		if(!rottenOranges.empty()) rottenOranges.push({-1, -1});
        	} else {
        		for(auto pr : directions) {
        			int nbrR = row + pr.first;
        			int nbrC = col + pr.second;
        			if(nbrR >= 0 && nbrR < nr && nbrC >= 0 && nbrC < nc) {
        				if(grid[nbrR][nbrC] == 1) {
        					grid[nbrR][nbrC] = 2;
        					freshOranges--;
        					rottenOranges.push({nbrR, nbrC});
        				}
        			}
        		}
        	}
        }
        return (freshOranges == 0 ? time : -1);
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<int> > grid(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> grid[i][j];
	}
	Solution *soln = new Solution();
	cout << soln->orangesRotting(grid) << nl;
	return;
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