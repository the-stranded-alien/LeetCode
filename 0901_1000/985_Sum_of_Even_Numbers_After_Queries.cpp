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

// You are given an integer array nums and an array queries where
// queries[i] = [vali, indexi]. For each query i, first, apply
// nums[indexi] = nums[indexi] + vali, then print the sum of the
// even values of nums. Return an integer array answer where answer[i]
// is the answer to the ith query.

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sumEven = 0;
        for(auto num : nums) {
        	if(num % 2 == 0) sumEven += num;
        }
        vector<int> se;
        se.reserve(queries.size());
        for(auto query : queries) {
        	int val = query[0];
        	int idx = query[1];
        	int curNum = nums[idx];
        	if(curNum % 2 == 0) sumEven -= curNum;
        	nums[idx] += val;
        	int newNum = nums[idx];
        	if(newNum % 2 == 0) sumEven += newNum;
        	se.push_back(sumEven);
        }
        return se;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	int q; cin >> q;
	vector<vector<int>> queries(q, vector<int>(2, 0));
	for(int i = 0; i < q; i++) cin >> queries[i][0] >> queries[i][1];
	Solution *soln = new Solution();
	vector<int> se = soln->sumEvenAfterQueries(nums, queries);
	for(auto num : se) cout << num << " ";
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