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

// Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	int m = matrix.size(); // Ending Row Index
    	int n = matrix[0].size(); // Ending Column Index
    	int k = 0; // Starting Row Index
    	int l = 0; // Starting Column Index
    	vector<int> result;
    	result.reserve((m * n));
		
		while((k < m) && (l < n)) {
			// Add the first row from remaining rows !
			for(int i = l; i < n; i++) result.push_back(matrix[k][i]);
			k++;
			// Add the last column from the remaining columns !
			for(int i = k; i < m; i++) result.push_back(matrix[i][n - 1]);
			n--;
			// Add the last row from the remaining rows !
			if(k < m) {
				for(int i = n - 1; i >= l; i--) result.push_back(matrix[m - 1][i]);
				m--;
			}
			// Add the first column from the remaining columns !	
			if(l < n) {
				for(int i = m - 1; i >= k; i--) result.push_back(matrix[i][l]);
				l++;
			}
		}  
    	return result;
    }
};

void solve() {
	// Main Code Goes Here !!
	int m;
	int n;
	cin >> m >> n;
	vvi matrix;
	int temp;
	for(int i = 0; i < m; i++) {
		vi row;
		for(int j = 0; j < n; j++) {
			cin >> temp;
			row.pb(temp);
		}
		matrix.pb(row);
	}
	Solution *soln = new Solution();
	vi spiral = soln->spiralOrder(matrix);
	for(auto e : spiral) cout << e << " ";
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