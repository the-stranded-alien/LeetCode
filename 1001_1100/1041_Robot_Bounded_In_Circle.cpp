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

// On an infinite plane, a robot initially stands at (0, 0) and faces north.
// Note that:
// The north direction is the positive direction of the y-axis.
// The south direction is the negative direction of the y-axis.
// The east direction is the positive direction of the x-axis.
// The west direction is the negative direction of the x-axis.
// The robot can receive one of three instructions:
// "G": go straight 1 unit.
// "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
// "R": turn 90 degrees to the right (i.e., clockwise direction).
// The robot performs the instructions given in order, and repeats them forever.
// Return true if and only if there exists a circle in the plane such that
// the robot never leaves the circle.

class Solution {
public:
	bool isRobotBounded(string instructions) {
    	// North = 0, East = 1, South = 2, West = 3 (Clockwise)
    	vector<pair<int, int> > directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    	// Initial Position is in center and direction is facing North
    	int x = 0;
    	int y = 0;
    	int dir = 0;
    	for(char instruction : instructions) {
    		if(instruction == 'L') dir = (dir + 3) % 4;
    		else if(instruction == 'R') dir = (dir + 1) % 4;
    		else {
    			x += directions[dir].first;
    			y += directions[dir].second;
    		}
    	}
    	// After one cycle, if robot returns into initial position
    	// or robot doesn't face North then it's cyclic path.
    	return ((x == 0 && y == 0) || (dir != 0));
    }
};

void solve() {
	// Main Code Goes Here !!
	string instructions; cin >> instructions;
	
	Solution *soln = new Solution();
	cout << soln->isRobotBounded(instructions);

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