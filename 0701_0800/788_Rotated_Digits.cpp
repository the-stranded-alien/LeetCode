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

// An integer x is a good if after rotating each digit
// individually by 180 degrees, we get a valid number that
// is different from x. Each digit must be rotated - we cannot
// choose to leave it alone.
// A number is valid if each digit remains a digit after rotation.
// For example:
// 0, 1, and 8 rotate to themselves,
// 2 and 5 rotate to each other (in this case they are rotated in
// a different direction, in other words, 2 or 5 gets mirrored),
// 6 and 9 rotate to each other, and
// the rest of the numbers do not rotate to any other number and
// become invalid.
// Given an integer n, return the number of good integers in the
// range [1, n].

class Solution {
private:
	bool isValidAndChanged(int n) {
		bool res = false;
		while(n) {
			int d = n % 10;
			if(d == 2 || d == 5 || d == 6 || d == 9) res = true;
			else if(d == 3 || d == 4 || d == 7) return false;
			n /= 10;
		}
		return res;
	}
public:
	int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
        	if(isValidAndChanged(i)) count++;
        }
        return count;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	
	Solution *soln = new Solution();
	cout << soln->rotatedDigits(n);

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