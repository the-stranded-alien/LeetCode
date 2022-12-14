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

// There is a special kind of apple tree that grows apples every day
// for n days. On the ith day, the tree grows apples[i] apples that
// will rot after days[i] days, that is on day i + days[i] the apples
// will be rotten and cannot be eaten. On some days, the apple tree does
// not grow any apples, which are denoted by apples[i] == 0 and
// days[i] == 0. You decided to eat at most one apple a day
// (to keep the doctors away). Note that you can keep eating after the first n days.
// Given two integer arrays days and apples of length n, return the
// maximum number of apples you can eat.

class Solution {
public:
	int eatenApples(vector<int>& apples, vector<int>& days) {
        int applesEaten = 0;
        int dayCount = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minHeap; 
    	int n = apples.size();
    	
    	while(true) {
    		if(dayCount < n && apples[dayCount]) minHeap.push({dayCount + days[dayCount], apples[dayCount]}); 
    		while(!minHeap.empty() && minHeap.top().first <= dayCount) minHeap.pop();
    		if(minHeap.empty()) {
    			if(dayCount >= n) break;
    		}
    		else {
    			pair<int, int> tp = minHeap.top();
    			minHeap.pop();
    			int rotOn = tp.first;
    			int count = tp.second;
    			if(rotOn > dayCount) {
    				applesEaten++;
    				count--;
    				if(count > 0) minHeap.push({rotOn, count});
    			}
    		}
    		dayCount++;
    	}
    	return applesEaten;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi apples(n);
	vi days(n);
	for(int i = 0; i < n; i++) cin >> apples[i];
	for(int i = 0; i < n; i++) cin >> days[i];
	
	Solution *soln = new Solution();
	cout << soln->eatenApples(apples, days);

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