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

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int maxArea = 0;
        int itr1 = 0;
        int itr2 = sz - 1;
        while (itr1 < itr2) {
        	int curArea = ((itr2 - itr1) * min(height[itr1], height[itr2]));
        	if (curArea > maxArea) {
        		maxArea = curArea;	
       		 	// cout << maxArea << nl;
        	}
        	if(height[itr1] < height[itr2]) {
        		int cur = height[itr1];
        		itr1++;
        		while((itr1 < itr2) && (cur > height[itr1])) {
        			itr1++;
        			if(height[itr1] > cur) break;
        		}
        	} 
        	else {
        		int cur = height[itr2];
        		itr2--;
        		while((itr1 < itr2) && (cur > height[itr2])) {
        			itr2--;
        			if(height[itr2] > cur) break;
        		}
        	}
        }
        return maxArea;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> height;
	int temp;
	while(n--) {
		cin >> temp;
		height.push_back(temp);
	}
	Solution *soln = new Solution();
	cout << soln->maxArea(height) << nl;
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