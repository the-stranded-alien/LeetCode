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

// You are given two 0-indexed binary arrays nums1 and nums2.
// Find the widest pair of indices (i, j) such that i <= j
// and nums1[i] + nums1[i+1] + ... + nums1[j] ==
// nums2[i] + nums2[i+1] + ... + nums2[j].
// The widest pair of indices is the pair with the largest
// distance between i and j. The distance between a pair of
// indices is defined as j - i + 1.
// Return the distance of the widest pair of indices. If no
// pair of indices meets the conditions, return 0.

class Solution {
public:
	int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int diff = 0;
        int maxWidth = 0;
        unordered_map<int, int> map;
        map[0] = 0;
        for(int i = 0; i < n; i++) {
        	diff += (nums1[i] - nums2[i]);
        	if(map.find(diff) == map.end()) map[diff] = i + 1;
        	else {
        		if((i - map[diff] + 1) > maxWidth) maxWidth = (i - map[diff] + 1);
        	} 
        }
        return maxWidth;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums1(n);
	for(int i = 0; i < n; i++) cin >> nums1[i];
	vi nums2(n);
	for(int i = 0; i < n; i++) cin >> nums2[i];
	
	Solution *soln = new Solution();
	cout << soln->widestPairOfIndices(nums1, nums2);

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