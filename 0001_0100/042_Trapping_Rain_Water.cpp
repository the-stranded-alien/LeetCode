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

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

class Solution {
public:
	// Dynamic Programming
    int trapDP(vector<int>& height) {
        if(height.empty()) return 0;
        int water = 0;
        int h = height.size();
        vector<int> leftMaxSoFar(h, 0);
        vector<int> rightMaxSoFar(h, 0);
        leftMaxSoFar[0] = height[0];
        for(int i = 1; i < h; i++) {
        	leftMaxSoFar[i] = max(height[i], leftMaxSoFar[i - 1]);
        }
        rightMaxSoFar[h - 1] = height[h - 1];
        for(int i = h - 2; i >= 0; i--) {
        	rightMaxSoFar[i] = max(height[i], rightMaxSoFar[i + 1]);
        }
        for(int i = 1; i < h - 1; i++) {
        	water += min(leftMaxSoFar[i], rightMaxSoFar[i]) - height[i];
        }
        return water;
    }

    // Stack
    int trapStack(vector<int>& height) {
        int water = 0;
        int itr = 0;
        stack<int> stk;
        while(itr < height.size()) {
        	while(!stk.empty() && (height[itr] > height[stk.top()])) {
        		int top = stk.top();
        		stk.pop();
        		if(stk.empty()) break;
        		int dist = itr - stk.top() - 1;
        		int bh = min(height[itr], height[stk.top()]) - height[top];
        		water += (dist * bh);
        	}
        	stk.push(itr++);
        }
        return water;
    }

    // Two Pointers
    int trapTP(vector<int>& height) {
        int leftPtr = 0;
        int rightPtr = height.size() - 1;
        int water = 0;
        int leftMaxSoFar = 0;
        int rightMaxSoFar = 0;
        while(leftPtr < rightPtr) {
        	if(height[leftPtr] < height[rightPtr]) {
        		height[leftPtr] >= leftMaxSoFar ? (leftMaxSoFar = height[leftPtr]) : water += (leftMaxSoFar - height[leftPtr]);
        		leftPtr++;
        	} else {
        		height[rightPtr] >= rightMaxSoFar ? (rightMaxSoFar = height[rightPtr]) : water += (rightMaxSoFar - height[rightPtr]);
        		rightPtr--;
        	}
        }
        return water;
    }
};

void solve() {
	// Main Code Goes Here !!
	int h; cin >> h;
	vector<int> height(h, 0);
	for(int i = 0; i < h; i++) cin >> height[i];
	Solution *soln = new Solution();
	cout << soln->trapTP(height) << nl;
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