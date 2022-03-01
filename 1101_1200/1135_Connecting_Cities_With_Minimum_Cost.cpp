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

// There are n cities labeled from 1 to n. You are given the integer n and an array connections
// where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi
// (bidirectional connection) is costi. Return the minimum cost to connect all the n cities such
// that there is at least one path between each pair of cities. If it is impossible to connect all
// the n cities, return -1, The cost is the sum of the connections' costs used.

class DSU {
private:
	int *parent;
	int *rank;
	int components;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];
		components = n;
		for(int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	// Find Function with Path Compression 
	int find(int i) {
		if(parent[i] == -1) return i;
		return (parent[i] = find(parent[i]));
	}
	// Union By Rank
	void unionRank(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if(s1 != s2) {
			components--;
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
	int getComponents() { return components; }
};

class Graph {
private:
	// Edge List
	vector< vector<int> > edgeList;
	int V;
public:
	Graph(int V) { this->V = V; }
	void addEdge(int x, int y, int w) {
		edgeList.push_back({w, x, y});
	}
	int kruskalMST() {
		sort(edgeList.begin(), edgeList.end());
		int minCost = 0;
		DSU dsu(V);
		for(auto edge : edgeList) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			if(dsu.find(x) != dsu.find(y)) {
				dsu.unionRank(x, y);
				minCost += w;
			}
		}
		if(dsu.getComponents() == 1) return minCost;
		else return -1;
	}
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
    	Graph graph(n);
    	for(auto con : connections) {
    		graph.addEdge((con[0] - 1), (con[1] - 1), con[2]);
    	}
    	return graph.kruskalMST();
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	int c; cin >> c;
	vector< vector<int> > connections(c, vector<int>(3, 0));
	for(int i = 0; i < c; i++) {
		cin >> connections[i][0]; // X-i
		cin >> connections[i][1]; // Y-i
		cin >> connections[i][2]; // Cost-i
	}
	Solution *soln = new Solution();
	int mc = soln->minimumCost(n, connections);
	cout << mc << nl;
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