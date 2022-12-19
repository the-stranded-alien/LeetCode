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

// Given a positive integer n, find the smallest integer which has
// exactly the same digits existing in the integer n and is greater
// in value than n. If no such positive integer exists, return -1.
// Note that the returned integer should fit in 32-bit integer, if
// there is a valid answer but it does not fit in 32-bit integer,
// return -1.

class Solution {
public:
	
	// In-Built Function
	// int nextGreaterElement(int n) {
    //  auto digits = to_string(n);
    // 	next_permutation(begin(digits), end(digits));
    // 	auto res = stoll(digits);
    // 	return (res > INT_MAX || res <= n) ? -1 : res;
    // }

	// Next Permutation
    int nextGreaterElement(int n) {
    	auto digits = to_string(n);
    	int itr = digits.length() - 2;
    	while(itr >= 0 && digits[itr + 1] <= digits[itr]) itr--;
    	if(itr < 0) return -1;
    	int x = digits.length() - 1;
    	while(x >= 0 && digits[x] <= digits[itr]) x--;
    	swapper(digits, itr, x);
    	rev(digits, itr + 1);
    	auto res = stoll(digits);
    	return (res > INT_MAX || res <= n) ? -1 : res;
    }

    void swapper(string &arr, int i, int j) {
    	char temp = arr[i];
    	arr[i] = arr[j];
    	arr[j] = temp;
    }

    void rev(string &arr, int s) {
    	int start = s;
    	int end = arr.length() - 1;
    	while(start < end) {
    		swapper(arr, start, end);
    		start++;
    		end--;
    	}
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	
	Solution *soln = new Solution();
	cout << soln->nextGreaterElement(n);

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