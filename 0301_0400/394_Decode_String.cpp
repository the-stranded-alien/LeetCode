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

// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the
// square brackets is being repeated exactly k times. Note that k is guaranteed
// to be a positive integer.
// You may assume that the input string is always valid; there are no extra
// white spaces, square brackets are well-formed, etc. Furthermore, you may
// assume that the original data does not contain any digits and that digits
// are only for those repeat numbers, k. For example, there will not be input
// like 3a or 2[4]. The test cases are generated so that the length of the
// output will never exceed 105.

class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(char c : s) {
        	string decodedString = "";
        	if(c != ']') {
        		stk.push(c);
        	} else {
        		while(!stk.empty() && stk.top() != '[') {
        			char cur = stk.top();
        			stk.pop();
        			decodedString += cur;
        		}
        		stk.pop();
        		int k = 0;
        		int m = 1;
        		while(!stk.empty() && isdigit(stk.top())) {
        			int curDig = stk.top() - '0';
        			stk.pop();
        			k += (curDig * m);
        			m = m * 10;
        		}
        		reverse(decodedString.begin(), decodedString.end());
        		for(int i = 0; i < k; i++) {
        			for(char x : decodedString) stk.push(x);
        		}
        	}
        }
        string res = "";
        while(!stk.empty()) {
        	res += stk.top();
        	stk.pop();
   		}
        reverse(res.begin(), res.end());
    	return res;
    }
};

void solve() {
	// Main Code Goes Here !!
	string inp;
	cin >> inp;
	Solution *soln = new Solution();
	cout << soln->decodeString(inp) << nl;
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