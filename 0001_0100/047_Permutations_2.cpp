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

// Given a collection of numbers, nums, that might contain duplicates, return all
// possible unique permutations in any order.

class Solution {
public:
	// void permuteUniqueHelper(vector<int> &nums, int idx, set< vector<int> > &ups) {
	// 	if(idx == nums.size()) {
	// 		ups.insert(nums);
	// 		return;
	// 	}
	// 	for(int itr = idx; itr < nums.size(); itr++) {
	// 		swap(nums[idx], nums[itr]);
	// 		permuteUniqueHelper(nums, idx + 1, ups);
	// 		swap(nums[idx], nums[itr]);
	// 	}
	// 	return;
	// }

    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     vector< vector<int> > uniquePermutations;
    //     set< vector<int> > uniquePermutationsSet;
    //     permuteUniqueHelper(nums, 0, uniquePermutationsSet);
    //     for(auto vec : uniquePermutationsSet) {
    //     	uniquePermutations.push_back(vec);
    //     }
    //     return uniquePermutations;
    // }

	void permuteUniqueHelper(vector<int> &nums, vector<bool> &visited, vector<int> &cur, vector< vector<int> > &res) {
		if(cur.size() == nums.size()) {
			res.push_back(cur);
			return;
		}
		for(int i = 0; i < nums.size(); i++) {
			if(visited[i] == true) continue;
			if((i == 0) || (nums[i] != nums[i - 1]) || ((nums[i] == nums[i - 1]) && (visited[i - 1] == true))) {
				visited[i] = true;
				cur.push_back(nums[i]);
				permuteUniqueHelper(nums, visited, cur, res);
				cur.pop_back();
				visited[i] = false;
			}
		}
		return;
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	if(nums.size() == 0) return {};
    	sort(nums.begin(), nums.end());
    	vector<bool> visited(nums.size(), false);
    	vector<int> cur;
    	vector< vector<int> > res;
    	permuteUniqueHelper(nums, visited, cur, res);
    	return res;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	vvi uniquePermutations = soln->permuteUnique(nums);
	for(auto perm : uniquePermutations) {
		for(auto num : perm) cout << num << " ";
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