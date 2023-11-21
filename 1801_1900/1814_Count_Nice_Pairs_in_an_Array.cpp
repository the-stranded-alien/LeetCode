#include<iostream>
#include<vector>
#include<map>

using namespace std;

// You are given an array nums that consists of non-negative integers.
// Let us define rev(x) as the reverse of the non-negative integer x.
// For example, rev(123) = 321, and rev(120) = 21. A pair of indices
// (i, j) is nice if it satisfies all of the following conditions:
// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since that number
// can be too large, return it modulo 109 + 7.

class Solution {
public:
    int reverse(int num) {
        int rev = 0;
        while(num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    int countNicePairs(vector<int> &nums) {
        const int MOD = 1000000007;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long int res = 0;
        for(int i = 0; i < len - 1; i++) {
            long long int count = 1;
            while(i < len - 1 && nums[i] == nums[i + 1]) {
                count++;
                i++;
            }
            res = (res % MOD + (count * (count - 1)) / 2) % MOD;
        }
        return static_cast<int>(res);
    }
};

// TLE
// class Solution {
// public:
//     int reverse(int num, map<int, int>& existingReverse) {
//         if(existingReverse.count(num)) {
//             return existingReverse.at(num);
//         }
//         int original = num;
//         int rev = 0;
//         while(num > 0) {
//             int dig = num % 10;
//             rev = (rev * 10 + dig);
//             num /= 10;
//         }
//         existingReverse.insert(make_pair(original, rev));
//         return rev;

//     }
//     int countNicePairs(vector<int>& nums) {
//         int nicePairs = 0;
//         map<int, int> existingReverse;
//         for(int i = 0; i < nums.size() - 1; i++) {
//             for(int j = i + 1; j < nums.size(); j++) {
//                 if(nums[i] + reverse(nums[j], existingReverse) == reverse(nums[i], existingReverse) + nums[j]) {
//                     nicePairs = (nicePairs + 1) % 1000000007;
//                 }
//             }
//         }
//         return nicePairs;
//     }
// };

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    Solution *soln = new Solution();
    cout << soln->countNicePairs(nums);
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