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

// The next greater element of some element x in an array is the first greater
// element that is to the right of x in the same array. You are given two
// distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset
// of nums2. For each 0 <= i < nums1.length, find the index j such that
// nums1[i] == nums2[j] and determine the next greater element of nums2[j]
// in nums2. If there is no next greater element, then the answer for this
// query is -1. Return an array ans of length nums1.length such that ans[i]
// is the next greater element as described above.
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monotonicStack;
        unordered_map<int, int> ump;
        for(int i = 0; i < nums2.size(); i++) {
        	while(!monotonicStack.empty() && nums2[i] > monotonicStack.top()) {
        		ump[monotonicStack.top()] = nums2[i];
        		monotonicStack.pop();
        	}
        	monotonicStack.push(nums2[i]);
        }
        while(!monotonicStack.empty()) {
        	ump[monotonicStack.top()] = -1;
        	monotonicStack.pop();
        }
        vector<int> nge(nums1.size(), 0);
        for(int i = 0; i < nums1.size(); i++) nge[i] = ump[nums1[i]];
        return nge;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n1; cin >> n1;
	vector<int> nums1(n1, 0);
	for(int i = 0; i < n1; i++) cin >> nums1[i];
	int n2; cin >> n2;
	vector<int> nums2(n2, 0);
	for(int i = 0; i < n2; i++) cin >> nums2[i];
	Solution *soln = new Solution();
	vi nge = soln->nextGreaterElement(nums1, nums2);
	for(auto ele : nge) cout << ele << " ";
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