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

// You are given a 0-indexed integer array nums of length n.
// The average difference of the index i is the absolute difference between the
// average of the first i + 1 elements of nums and the average of the last
// n - i - 1 elements. Both averages should be rounded down to the nearest integer.
// Return the index with the minimum average difference. If there are multiple such
// indices, return the smallest one.
// Note:
// The absolute difference of two numbers is the absolute value of their difference.
// The average of n elements is the sum of the n elements divided (integer division) by n.
// The average of 0 elements is considered to be 0.

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = int(nums.size());
        int ans = -1;
        int minAvgDiff = numeric_limits<int>::max();
        
        vector<long long> prefixSum(n + 1);
        vector<long long> suffixSum(n + 1);
        
        for (int index = 0; index < n; ++index) {
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        }
        
        for (int index = n - 1; index >= 0; --index) {
            suffixSum[index] = suffixSum[index + 1] + nums[index];
        }
        
        for (int index = 0; index < n; ++index) {
            long long leftPartAverage = prefixSum[index + 1];
            leftPartAverage /= (index + 1);
            long long rightPartAverage = suffixSum[index + 1];
            if (index != n - 1) {
                rightPartAverage /= (n - index - 1);
            }
            
            int currDifference = int(abs(leftPartAverage - rightPartAverage));
            if (currDifference < minAvgDiff) {
                minAvgDiff = currDifference;
                ans = index;
            }
        }

        return ans;
    }
};

// class Solution {
// public:
// 	int minimumAverageDifference(vector<int>& nums) {
//         int n = nums.size();
//         // Prefix Sum
//         vector<int> prefix(n, 0);
//         prefix[0] = nums[0];
//         for(int i = 1; i < n; i++) {
//         	prefix[i] = prefix[i - 1] + nums[i];
//         }
//         // Suffix Sum
//         vector<int> suffix(n, 0);
//         suffix[n - 1] = nums[n - 1];
//         for(int i = n - 2; i >= 0; i--) {
//         	suffix[i] = suffix[i + 1] + nums[i];
//         }
// 		reverse(suffix.begin(), suffix.end());


//         int minAvgDiff = INT_MAX;
//         int minAvgDiffIndex = 0;

//     	for(int itr = 0; itr < n; itr++) {
//     		int first = itr + 1;
//     		int last = n - itr - 1;
//     		int sum1 = (first - 1 >= 0) ? prefix[first - 1] : 0;
// 			int sum2 = (last - 1 >= 0) ? suffix[last - 1] : 0; 		
//     		int avg1 = (sum1 > 0) ? sum1 / first : 0;
//     		int avg2 = (sum2 > 0) ? sum2 / last : 0;
//     		int curMAD = abs(avg1 - avg2);
//     		if(minAvgDiff > curMAD) {
//     			minAvgDiff = curMAD;
//     			minAvgDiffIndex = itr;
//     		}
//     	}
//     	return minAvgDiffIndex;    
//     }
// };

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) cin >> nums[i];
	
	Solution *soln = new Solution();
	cout << soln->minimumAverageDifference(nums);

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