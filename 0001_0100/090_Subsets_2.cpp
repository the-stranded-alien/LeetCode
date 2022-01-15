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

// Given an integer array nums that may contain duplicates,
// return all possible subsets (the power set).
// The solution set must not contain duplicate subsets.
// Return the solution in any order.

class Solution {
public:
	// void subsetsWithDupHelper(vector<int> &nums, vector<int> &cur, set<vector<int>> &sub, int idx) {
	// 	if(idx == nums.size()) {
	// 		vector<int> copy(cur);
	// 		sort(copy.begin(), copy.end());
	// 		sub.insert(copy);
	// 		return;
	// 	}
	// 	subsetsWithDupHelper(nums, cur, sub, (idx + 1));
	// 	cur.push_back(nums[idx]);
	// 	subsetsWithDupHelper(nums, cur, sub, (idx + 1));
	// 	cur.pop_back();
	// 	return;
	// }

    // vector<vector<int>> subsetsWithDupRec(vector<int>& nums) {
    //     set< vector<int> > sub;
    //     vector< vector<int> > subsets;
    //     vector<int> cur;
    //     subsetsWithDupHelper(nums, cur, sub, 0);
    //     for(auto s : sub) subsets.push_back(s);
    //     return subsets;
    // }

    vector<vector<int>> subsetsWithDupItr(vector<int> &nums) {
    	sort(nums.begin(), nums.end());
    	vector< vector<int> > subsets;
    	vector<int> curSubset;
    	subsets.push_back(curSubset);
    	curSubset.push_back(nums[0]);
    	subsets.push_back(curSubset);
    	int prev = nums[0];
    	int count = 1;
    	for(int itr = 1; itr < nums.size(); itr++) {
    		int st = 0;
    		int sz = subsets.size();
    		if(nums[itr] == prev) st = sz - count;
    		count = 0;
    		for(int j = st; j < sz; j++) {
    			curSubset = subsets[j];
    			curSubset.push_back(nums[itr]);
    			subsets.push_back(curSubset);
    			count++;
    		}
    		prev = nums[itr];
    	}
    	return subsets;
    }

    void subsetsWithDupHelper(int idx, vector<int> &nums, vector<int> &cur, vector<vector<int>> &subsets, bool isPicked) {
    	if(idx >= nums.size()) return;
    	int val = nums[idx];
    	// Do not pick the current element
    	subsetsWithDupHelper((idx + 1), nums, cur, subsets, false);
    	// Check for duplicate
    	if((idx >= 1) && (nums[idx - 1] == nums[idx]) && (!isPicked)) return;
    	// Pick the current element
    	cur.push_back(val);
	   	subsetsWithDupHelper((idx + 1), nums, cur, subsets, true);
	   	subsets.push_back(cur);
    	cur.pop_back();
    	return;
    }

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector< vector<int> > subsets;
		vector<int> cur;
		subsets.push_back({});
		subsetsWithDupHelper(0, nums, cur, subsets, true);
		return subsets;
	}
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	vi nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	vvi subsets = soln->subsetsWithDup(nums);
	for(auto sub : subsets) {
		for(auto s : sub) cout << s << " ";
		cout << nl;
	}
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