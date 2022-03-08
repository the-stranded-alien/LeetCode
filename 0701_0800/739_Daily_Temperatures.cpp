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

// Given an array of integers temperatures represents the daily temperatures,
// return an array answer such that answer[i] is the number of days you have
// to wait after the ith day to get a warmer temperature. If there is no
// future day for which this is possible, keep answer[i] == 0 instead.

class Solution {
public:
   //  vector<int> dailyTemperatures(vector<int>& temperatures) {
   //      int n = temperatures.size();
   //      vector<int> nextWarmerDay(n, 0);
   //      int hottest = 0;
   //      for(int i = (n - 1); i >= 0; i--) {
			// int curTemp = temperatures[i];
			// if(curTemp >= hottest) {
			// 	hottest = curTemp;
			// 	continue;
			// }
			// int days = 1;
			// while(temperatures[i + days] <= curTemp) {
			// 	days += nextWarmerDay[i + days];		
			// }
			// nextWarmerDay[i] = days;
   //      }
   //      return nextWarmerDay;
   //  }

    // Monotonic Stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    	int n = temperatures.size();
    	vector<int> nextWarmerDay(n, 0);
    	stack<int> monotonicStack;
    	for(int curDay = 0; curDay < n; curDay++) {
    		int curTemp = temperatures[curDay];
    		// Pop untill the current day's temperature is not
    		// warmer than the temperature at the top of the stack.
    		while(!monotonicStack.empty() && temperatures[monotonicStack.top()] < curTemp) {
    			int prevDay = monotonicStack.top();
                monotonicStack.pop();
    			nextWarmerDay[prevDay] = curDay - prevDay;
    		}
    		monotonicStack.push(curDay);
    	}
    	return nextWarmerDay;
    }
};

void solve() {
	// Main Code Goes Here !!
	int t; cin >> t;
	vector<int> temperatures(t, 0);
	for(int i = 0; i < t; i++) cin >> temperatures[i];
	Solution *soln = new Solution();
	vi nextWarmerDay = soln->dailyTemperatures(temperatures);
	for(auto day : nextWarmerDay) cout << day << " ";
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