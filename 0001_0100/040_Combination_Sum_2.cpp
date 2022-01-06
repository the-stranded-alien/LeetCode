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

// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

class Solution {
public:
	void combinationSum2Helper(vector<int> &curResult, int idx, set< vector<int> > &resultSet, vector<int> &candidates, int target) {
		if (target < 0) return;
		else {
			if (target == 0) {
				resultSet.insert(curResult);
				return;
			} 
			else {
				int prev = -1;
				for(int itr = idx; itr < candidates.size(); itr++) {
					if(prev != candidates[itr]) {
						curResult.push_back(candidates[itr]);
						combinationSum2Helper(curResult, itr + 1, resultSet, candidates, target - candidates[itr]);
						prev = candidates[itr];
						curResult.pop_back();
					}
				}
				return;
			}
		}
	}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set< vector<int> > resultSet;
        vector<int> curResult;
        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(curResult, 0, resultSet, candidates, target);
        vector< vector<int> > result(resultSet.begin(), resultSet.end());        
        return result;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	vi candidates;
	candidates.reserve(100);
	int temp;
	while(n--) {
		cin >> temp;
		candidates.pb(temp);
	}
	int target;
	cin >> target;
	Solution *soln = new Solution();
	vvi result = soln->combinationSum2(candidates, target);	
	for(auto cur : result) {
		for(auto ele : cur) {
			cout << ele << " ";
		}
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