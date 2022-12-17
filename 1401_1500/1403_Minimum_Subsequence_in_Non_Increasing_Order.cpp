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

// Given the array nums, obtain a subsequence of the array whose sum of
// elements is strictly greater than the sum of the non included elements
// in such subsequence. 
// If there are multiple solutions, return the subsequence with minimum
// size and if there still exist multiple solutions, return the subsequence
// with the maximum total sum of all its elements. A subsequence of an
// array can be obtained by erasing some (possibly zero) elements from
// the array. 
// Note that the solution with the given constraints is guaranteed 
// to be unique. Also return the answer sorted in non-increasing order.

class Solution {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		vector<int> sub;
        long long sum = 0;
        for(auto num : nums) sum += num;
        sort(nums.begin(), nums.end(), greater<int>());
    	long long subSum = 0;
    	int itr = 0;
    	while(subSum <= sum) {
    		int ele = nums[itr++];
    		subSum += ele;
    		sum -= ele;
    		sub.push_back(ele);
    	}
    	return sub;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vi nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	
	Solution *soln = new Solution();
	vi sub = soln->minSubsequence(nums);
	for(auto s : sub) cout << s << " ";
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