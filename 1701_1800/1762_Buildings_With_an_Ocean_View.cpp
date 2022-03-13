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

// There are n buildings in a line. You are given an integer array heights
// of size n that represents the heights of the buildings in the line.
// The ocean is to the right of the buildings. A building has an ocean
// view if the building can see the ocean without obstructions. Formally,
// a building has an ocean view if all the buildings to its right have a
// smaller height. Return a list of indices (0-indexed) of buildings that
// have an ocean view, sorted in increasing order.

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> idxStk;
        int h = heights.size() - 1;
        for(int i = h; i >= 0; i--) {
        	if(idxStk.empty() || heights[idxStk.top()] < heights[i]) {
        		idxStk.push(i);
        	}
        }
        vector<int> buildings;
        while(!idxStk.empty()) {
        	buildings.push_back(idxStk.top());
        	idxStk.pop();
        }
        return buildings;
    }
};

void solve() {
	// Main Code Goes Here !!
	int h; cin >> h;
	vector<int> heights(h, 0);
	for(int i = 0; i < h; i++) cin >> heights[i];
	Solution *soln = new Solution();
	vi buildings = soln->findBuildings(heights);
	for(auto building : buildings) cout << building << " ";
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