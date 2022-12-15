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

// Given a string s of zeros and ones, return the maximum score
// after splitting the string into two non-empty substrings
// (i.e. left substring and right substring).
// The score after splitting a string is the number of zeros
// in the left substring plus the number of ones in the right
// substring.

class Solution {
public:
	int maxScore(string s) {
        int l = s.length();
        vector<int> zeros(l, 0);
        vector<int> ones(l, 0);
        zeros[0] = (s[0] == '0') ? 1 : 0;
        ones[l - 1] = (s[l - 1] == '1') ? 1 : 0;
        for(int i = 1; i < l; i++) {
        	int add = (s[i] == '0') ? 1 : 0;
        	zeros[i] = zeros[i - 1] + add;
        };
        for(int i = (l - 2); i >= 0; i--) {
        	int add = (s[i] == '1') ? 1 : 0;
        	ones[i] = ones[i + 1] + add;
        }

        int maxSum = 0;
        for(int i = 1; i < l; i++) {
        	int cur = zeros[i - 1] + ones[i];
        	maxSum = max(maxSum, cur);
        }
        return maxSum;
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	
	Solution *soln = new Solution();
	cout << soln->maxScore(s);

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