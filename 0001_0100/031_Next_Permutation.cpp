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

// A permutation of an array of integers is an arrangement of its members into a sequence
// or linear order. For example, for arr = [1,2,3], the following are considered
// permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
// The next permutation of an array of integers is the next lexicographically greater
// permutation of its integer. More formally, if all the permutations of the array are
// sorted in one container according to their lexicographical order, then the next 
// permutation of that array is the permutation that follows it in the sorted container.
// If such arrangement is not possible, the array must be rearranged as the lowest
// possible order (i.e., sorted in ascending order).
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
// have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

class Solution {
public:
	void allPermutations(int idx, vector<int> &nums) {
		if(idx == nums.size()) {
			for(auto num : nums) cout << num << " ";
			cout << endl;
			return;
		}
		for(int itr = idx; itr < nums.size(); itr++) {
			swap(nums[itr], nums[idx]);
			allPermutations(idx + 1, nums);
			swap(nums[itr], nums[idx]);
		}
		return;
	}

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        // Index of the First Element that is
        // Smaller than the Element to its Right.
        int firstDec = -1;
        for(int i = (n - 2); i >= 0; i--) {
        	if(nums[i] < nums[i + 1]) {
        		firstDec = i;
        		break;
        	}
        }
        if(firstDec == -1) {
        	reverse(nums.begin(), nums.end());
        	return;
        }
        int idx = n - 1;
        // Swap From Right to Left to Find First
        // Element that is Greater than 'firstDec'
        for(int i = (n - 1); i >= (firstDec + 1); i--) {
        	if(nums[i] > nums[firstDec]) {
        		idx = i;
        		break;
        	}
        }
        // Swap the Elements
        swap(nums[firstDec], nums[idx]);
        // Reverse the Elements from (firstDec + 1) to End
        reverse(nums.begin() + firstDec + 1, nums.end());
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n, 0);
	for(int i = 0; i < n; i++) cin >> nums[i];
	Solution *soln = new Solution();
	soln->nextPermutation(nums);
	for(auto num : nums) cout << num << " ";
	cout << nl;
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