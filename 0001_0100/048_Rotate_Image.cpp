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

// You are given an n x n 2D matrix representing an image,
// rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify
// the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	// Transpose
    	for(int i = 0; i < n; i++) {
    		for(int j = (i + 1); j < n; j++) {
    			swap(matrix[i][j], matrix[j][i]);
    		}
    	}
    	// Reverse Individual Rows
    	for(int row = 0; row < n; row++) {
    		reverse(matrix[row].begin(), matrix[row].end());
    	}
        return;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	vvi matrix(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}	
	Solution *soln = new Solution();
	soln->rotate(matrix);
	for(auto row : matrix) {
		for(auto col : row) {
			cout << col << " ";
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