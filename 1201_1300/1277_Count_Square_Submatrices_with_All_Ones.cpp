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

// Given a m * n matrix of ones and zeros, return how many square submatrices
// have all ones.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector< vector<int> > additiveTable(m, vector<int>(n, 0));
        additiveTable[0][0] = matrix[0][0];
        for(int i = 1; i < n; i++) {
        	additiveTable[0][i] = additiveTable[0][i - 1] + matrix[0][i];
        }
        for(int j = 1; j < m; j++) {
        	additiveTable[j][0] = additiveTable[j - 1][0] + matrix[j][0];
        }
        for(int i = 1; i < m; i++) {
        	for(int j = 1; j < n; j++) {
        		additiveTable[i][j] = (matrix[i][j] + additiveTable[i - 1][j] + additiveTable[i][j - 1] - additiveTable[i - 1][j - 1]);
        	}
        }

        int cs = 0;
        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		for(int sz = 1; sz <= min(m - i, n - j); sz++) {
        			int v = additiveTable[i + sz - 1][j + sz - 1];
        			if(i > 0) v -= additiveTable[i - 1][j + sz - 1];
        			if(j > 0) v -= additiveTable[i + sz - 1][j - 1];
        			if((i > 0) && (j > 0)) v += additiveTable[i - 1][j - 1];
        			if(v == (sz * sz)) cs++;
        		}
        	}
        }
        return cs;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m; cin >> m;
	int n; cin >> n;
	vector< vector<int> > matrix(m, vector<int>(n, 0));
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) cin >> matrix[i][j];
	}
	Solution *soln = new Solution();
	int cs = soln->countSquares(matrix);
	cout << cs << nl;
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