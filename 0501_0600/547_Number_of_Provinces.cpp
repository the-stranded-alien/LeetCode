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

// There are n cities. Some of them are connected, while some are not. If city
// a is connected directly with city b, and city b is connected directly with
// city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no
// other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1
// if the ith city and the jth city are directly connected, 
// and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.

class DSU {
private:
	int *parent;
	int *rank;
	int comp;
public:
	DSU(vector< vector<int> > &isConnected) {
		int n = isConnected.size();
		parent = new int[n];
		rank = new int[n];
		for(int i = 0; i < n; i++) { parent[i] = -1; rank[i] = 1; }
		comp = n;
		for(int i = 0; i < n; i++) {
			for(int j = (i + 1); j < n; j++) {
				if(isConnected[i][j] == 1) {
					unite(i, j);
				}
			}
		}
	} 
	
	int find(int i) {
		if(parent[i] == -1) return i;
		return (parent[i] = find(parent[i]));
	}

	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if(s1 != s2) {
			comp--;
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
		return;
	}
	int getNumberOfComp() {
		return comp;
	}
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected);
        return dsu.getNumberOfComp(); 
    }
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	vector< vector<int> > isConnected(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> isConnected[i][j];
	}	
	Solution *soln = new Solution();
	int numProv = soln->findCircleNum(isConnected);
	cout << numProv << nl;
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