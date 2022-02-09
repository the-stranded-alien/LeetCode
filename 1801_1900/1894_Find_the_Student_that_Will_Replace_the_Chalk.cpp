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

// There are n students in a class numbered from 0 to n - 1. The teacher
// will give each student a problem starting with the student number 0,
// then the student number 1, and so on until the teacher reaches the
// student number n - 1. After that, the teacher will restart the process,
// starting with the student number 0 again.
// You are given a 0-indexed integer array chalk and an integer k. 
// There are initially k pieces of chalk. When the student number i
// is given a problem to solve, they will use chalk[i] pieces of chalk
// to solve that problem. However, if the current number of chalk pieces
// is strictly less than chalk[i], then the student number i will be asked
// to replace the chalk.
// Return the index of the student that will replace the chalk.

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    	if(chalk.size() == 1) return 0;
    	int csum = 0;
    	for(auto c : chalk) csum += c;
    	if(k > csum) k = k % csum;
        int chalkLeft = k;
        while(true) {
        	for(int i = 0; i < chalk.size(); i++) {
        		if(chalkLeft >= chalk[i]) chalkLeft = chalkLeft - chalk[i];
        		else return i;	
        	}
        }
    }
};

void solve() {
	// Main Code Goes Here !!
	int c; cin >> c;
	vi chalk(c, 0);
	for(int i = 0; i < c; i++) cin >> chalk[i];
	int k; cin >> k;
	Solution *soln = new Solution();
	int cr = soln->chalkReplacer(chalk, k);
	cout << cr << nl;
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