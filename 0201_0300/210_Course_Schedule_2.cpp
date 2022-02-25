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

// There are a total of numCourses courses you have to take, labeled
// from 0 to numCourses - 1. You are given an array prerequisites where
// prerequisites[i] = [ai, bi] indicates that you must take course bi
// first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you
// have to first take course 1. Return the ordering of courses you
// should take to finish all courses. If there are many valid answers,
// return any of them. If it is impossible to finish all courses, return an empty array.

class Graph {
private:
	int V;
	list<int> *l;
public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}
	// Directed Graph
	void addEdge(int x, int y) {
		l[x].push_back(y);
	}
	// DFS based algorithm to Check if Directed Graph contains Cycle
	bool dfsCycleHelper(int node, vector<bool> &visited, vector<bool> &stack) {
		visited[node] = true;
		stack[node] = true;
		for(auto nbr : l[node]) {
			if(stack[nbr]) return true;
			else if(!visited[nbr]) {
				bool nbrFoundCycle = dfsCycleHelper(nbr, visited, stack);
				if(nbrFoundCycle) return true;
			}
		}
		stack[node] = false;
		return false;
	}

	// Check if Directed Graph Contains Cycle
	bool containsCycle() {
		vector<bool> visited(V, false);
		vector<bool> stack(V, false);
		for(int i = 0; i < V; i++) {
			if(!visited[i]) {
				if(dfsCycleHelper(i, visited, stack)) return true;
			}
		}
		return false;
	}
	// Topological Sort Using BFS
	vector<int> topologicalSortBFS() {
		vector<int> topSort;
		vector<int> inDegree(V, 0);
		for(int i = 0; i < V; i++) {
			for(auto nbr : l[i]) inDegree[nbr]++;
		}
		// BFS
		queue<int> q;
		// Init the Queue with Nodes having 0 inDegree
		for(int i = 0; i < V; i++) {
			if(inDegree[i] == 0) q.push(i);
		}
		while(!q.empty()) {
			int node = q.front();
			topSort.push_back(node);
			q.pop();
			// Iterate over nbrs of node and reduce their indegree by 1
			for(auto nbr : l[node]) {
				inDegree[nbr]--;
				// If Indegree of any nbr becomes 0 push it into queue
				if(inDegree[nbr] == 0) q.push(nbr);
			}
		}
		return topSort;
	}
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses);
        for(auto edge : prerequisites) g.addEdge(edge[1], edge[0]);
        if(g.containsCycle()) return {};
    	vector<int> topSort = g.topologicalSortBFS();
    	return topSort;
    }
};

void solve() {
	// Main Code Goes Here !!
	int nc; cin >> nc;
	int p; cin >> p;
	vector<vector<int> > prerequisites(p, vector<int>(2, 0));
	for(int i = 0; i < p; i++) cin >> prerequisites[i][0] >> prerequisites[i][1];	
	Solution *soln = new Solution();
	vi ts = soln->findOrder(nc, prerequisites);
	for(auto node : ts) cout << node << " ";
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