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

// Given a binary string s, return true if the longest contiguous segment of 1's
// is strictly longer than the longest contiguous segment of 0's in s, or return
// false otherwise.
// For example, in s = "110100010" the longest continuous segment of 1s
// has length 2, and the longest continuous segment of 0s has length 3.
// Note that if there are no 0's, then the longest continuous segment of
// 0's is considered to have a length 0. The same applies if there is no 1's.

class Solution {
public:
	bool checkZeroOnes(string s) {
    	int longestOnes = 0;
    	int longestZeros = 0;

    	// Ones
    	int cv = 0;
    	for(auto c : s) {
    		if(c == '1') cv++;
    		else {
    			longestOnes = max(longestOnes, cv);
    			cv = 0;
    		}
    	}
    	longestOnes = max(cv, longestOnes);
    	// Zeros
    	cv = 0;
    	for(auto c : s) {
    		if(c == '0') cv++;
    		else {
    			longestZeros = max(longestZeros, cv);
    			cv = 0;
    		}
    	}
    	longestZeros = max(cv, longestZeros);
    	return (longestOnes > longestZeros);    
    }
};

void solve() {
	// Main Code Goes Here !!
	string s; cin >> s;
	
	Solution *soln = new Solution();
	cout << soln->checkZeroOnes(s);

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