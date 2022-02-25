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

// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server
// connections forming a network where connections[i] = [ai, bi] represents a connection
// between servers ai and bi. Any server can reach other servers directly or indirectly
// through the network. A critical connection is a connection that, if removed, will make
// some servers unable to reach some other server.
// Return all critical connections in the network in any order.

class Graph {
private:
	int V;
	list<int> *nbrs;
	int time;
	bool *visited;
	int *discovery;
	int *low;
public:
	Graph(int V) {
		this->V = V;
		nbrs = new list<int>[V];
		time = 1;
		visited = new bool[V]{false};
		discovery = new int[V];
		low = new int[V];
	}
	void addEdge(int x, int y) {
		nbrs[x].push_back(y);
		nbrs[y].push_back(x);
	}
	void dfsHelper(int cur, int par, vector<vector<int> > &bridges) {
		visited[cur] = true;
		discovery[cur] = low[cur] = time++;
		for(auto nbr : nbrs[cur]) {
			if(!visited[nbr]) {
				dfsHelper(nbr, cur, bridges);
				low[cur] = min(low[cur], low[nbr]);
				if(low[nbr] > discovery[cur]) {
					bridges.push_back({cur, nbr});
				}
			} else if(nbr != par) {
				// Backedge
				low[cur] = min(low[cur], discovery[nbr]);
			}
		}
		return;
	}
	vector< vector<int> > findBridges() {
		vector<vector<int> > bridges;
		dfsHelper(0, -1, bridges);
		return bridges;
	}
};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Graph g(n);
        for(auto connection : connections) {
        	g.addEdge(connection[0], connection[1]);
        }
        vector<vector<int> > bridges = g.findBridges();
        return bridges;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	int c; cin >> c;
	vector<vector<int> > connections(c, vector<int>(2, 0));
	for(int i = 0; i < c; i++) cin >> connections[i][0] >> connections[i][1];
	Solution *soln = new Solution();
	vvi cc = soln->criticalConnections(n, connections);
	for(auto c : cc) cout << c[0] << " -- " << c[1] << nl;
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