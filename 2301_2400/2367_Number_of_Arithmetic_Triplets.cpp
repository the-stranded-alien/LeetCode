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

// unordered_map<int, int> mp;
//         int ans = 0;
//         for(auto i: nums){
//             if(mp.find(i-diff) != mp.end() && mp.find(i-2*diff) != mp.end()) ans = ans + mp[i-diff]* mp[i-2*diff];
//             mp[i]++;
//         }
//         return ans;

// You are given a 0-indexed, strictly increasing integer array nums
// and a positive integer diff. A triplet (i, j, k) is an arithmetic
// triplet if the following conditions are met:
// i < j < k,
// nums[j] - nums[i] == diff, and
// nums[k] - nums[j] == diff.
// Return the number of unique arithmetic triplets.



class Solution {
public:
	int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int, bool> map;
        int ans = 0;
        for(auto num : nums) {
        	ans += map[num - diff] * map[num - (2 * diff)];
        	map[num] = true;
        }
        return ans;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int diff; cin >> diff;

	Solution *soln = new Solution();
	cout << soln->arithmeticTriplets(nums, diff);

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