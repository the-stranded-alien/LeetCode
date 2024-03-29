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

// You are given an integer num. Rearrange the digits of num such
// that its value is minimized and it does not contain any leading zeros.
// Return the rearranged number with minimal value.
// Note that the sign of the number does not change after rearranging
// the digits.

class Solution {
public:
	long long smallestNumber(long long num) {
		if(num == 0) return num;
		else if(num > 0) {
			vector<int> digits;
			int zeroCount = 0;
			while(num) {
			 	int d = num % 10;
			 	if(d != 0) digits.push_back(d);
			 	else zeroCount++;
			 	num /= 10;
			}
			sort(digits.begin(), digits.end());
			vector<int> newDigits;
			newDigits.push_back(digits[0]);
			while(zeroCount--) newDigits.push_back(0);
			for(int i = 1; i < (int) digits.size(); i++) {
				newDigits.push_back(digits[i]);
			}
			reverse(newDigits.begin(), newDigits.end());
			long long nn = 0;
			long long m = 1;
			for(auto d : newDigits) {
				nn += (d * m);
				m *= 10;
			}
			return nn;
		} else {
			num = -num;
			vector<int> digits;
			while(num) { digits.push_back(num % 10); num /= 10; }
			sort(digits.begin(), digits.end());
			long long nn = 0;
			long long m = 1;
			for(auto d : digits) {
				nn += (d * m);
				m *= 10;
			}
			return -nn;
		}
    }
};

void solve() {
	// Main Code Goes Here !!
	long long n; cin >> n;
	
	Solution *soln = new Solution();
	cout << soln->smallestNumber(n);

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