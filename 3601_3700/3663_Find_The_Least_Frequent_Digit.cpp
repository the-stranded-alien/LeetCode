#include<iostream>
#include<vector>
using namespace std;

// Given an integer n, find the digit that occurs least frequently in its decimal representation.
// If multiple digits have the same frequency, choose the smallest digit.
// Return the chosen digit as an integer.
// The frequency of a digit x is the number of times it appears in the decimal representation of n.

class Solution {
public:
    int getLeastFrequentDigit(long long n) {
        vector<int> freq(10, 0);
        while(n > 0) {
            int digit = n % 10;
            n = n / 10;
            freq[digit] += 1;
        }
        int minCount = INT_MAX;
        int digitWithMinCount = 0;
        for(int i = 0; i < 10; i++) {
            if(freq[i] != 0 && minCount > freq[i]) {
                minCount = freq[i];
                digitWithMinCount = i;
            }
        }
        return digitWithMinCount;
    }
};

int main() {
    long long n; cin >> n;
    Solution *soln = new Solution();
    cout << soln->getLeastFrequentDigit(n) << endl;
    return 0;
}