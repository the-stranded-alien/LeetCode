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

// Alice and Bob have a different total number of candies. You are given two integer
// arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of
// the ith box of candy that Alice has and bobSizes[j] is the number of candies of
// the jth box of candy that Bob has.
// Since they are friends, they would like to exchange one candy box each so that
// after the exchange, they both have the same total amount of candy. The total
// amount of candy a person has is the sum of the number of candies in each box
// they have. Return an integer array answer where answer[0] is the number of
// candies in the box that Alice must exchange, and answer[1] is the number of
// candies in the box that Bob must exchange. If there are multiple answers,
// you may return any one of them. It is guaranteed that at least one answer exists.



class Solution {
public:
	vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = 0, bobSum = 0;
        for(auto a : aliceSizes) aliceSum += a;
        for(auto b : bobSizes) bobSum += b;
        int diff = (aliceSum - bobSum) / 2;
		set<int> aliceSet(aliceSizes.begin(), aliceSizes.end());
		set<int> bobSet(bobSizes.begin(), bobSizes.end());

		for(auto a : aliceSet) {
			if(bobSet.find(a - diff) != bobSet.end()) {
				return {a, a - diff};				
			}
		}    	
		return {};
    }
};

void solve() {
	// Main Code Goes Here !!
	int a, b;
	cin >> a >> b;
	vi aliceSizes(a);
	vi bobSizes(b);
	for(int i = 0; i < a; i++) cin >> aliceSizes[i];
	for(int i = 0; i < b; i++) cin >> bobSizes[i];

	Solution *soln = new Solution();
	vi swap = soln->fairCandySwap(aliceSizes, bobSizes);
	cout << swap[0] << " " << swap[1];

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