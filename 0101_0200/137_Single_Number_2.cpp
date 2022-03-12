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

// Given an integer array nums where every element appears three times
// except for one, which appears exactly once. Find the single element
// and return it. You must implement a solution with a linear runtime
// complexity and use only constant extra space.

class Solution {
public:
	void updateSum(vector<int> &sumArr, int num) {
		// Extract all bits of num
		for(int i = 0; i < 32; i++) {
			int ithBit = num & (1 << i);
			if(ithBit) sumArr[i]++;
		}
		return;
	}

	int numFromBitsArr(vector<int> &sumArr) {
		int num = 0;
		for(int i = 0; i < 32; i++) num += (sumArr[i] * (1 << i));
		return num;
	}

    int singleNumberSpace(vector<int>& nums) {
        // Sum the number of set bits for all the numbers at a given position.
        // Sum at each position would be either 3N or 3N + 1.
        // 3N -> Unique No. Doesn't have set bit here
        // 3N + 1 -> Unique No. Have set bit here
        vector<int> sumArr(32, 0);
        for(int num : nums) updateSum(sumArr, num);
        for(int i = 0; i < 32; i++) sumArr[i] %= 3;
        return numFromBitsArr(sumArr);	
    }

    int singleNumber(vector<int> &nums) {
    	int seenOnce = 0;
    	int seenTwice = 0;
    	for(auto num : nums) {
    		seenOnce = ~seenTwice & (seenOnce ^ num);
    		seenTwice = ~seenOnce & (seenTwice ^ num);
    	}
    	return seenOnce;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	int sn = soln->singleNumber(nums);
	cout << sn << nl;
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