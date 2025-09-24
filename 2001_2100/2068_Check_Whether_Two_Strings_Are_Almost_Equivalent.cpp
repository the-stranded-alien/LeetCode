#include<iostream>
using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int freq1[26] = {0}, freq2[26] = {0};
        for (char c1 : word1) {
            freq1[c1 - 'a']++;
        }
        for (char c2 : word2) {
            freq2[c2 - 'a']++;
        }
        int diff = 0;
        for(int i = 0; i < 26; i++) {
            diff = abs(freq1[i] - freq2[i]);
            cout << diff;
            if(diff > 3) return false;
        }
        return true;
    }
    bool checkAlmostEquivalentOptimized(string word1, string word2) {
        int freq[26] = {0};
        for (char c1 : word1) freq[c1 - 'a']++;
        for (char c2 : word2) freq[c2 - 'a']--;
        
        for(int i = 0; i < 26; i++) {
            if (abs(freq[i]) > 3) return false;
        }
        return true;
    }
};

int main() {
    string word1, word2;
    cin >> word1;
    cin >> word2;
    Solution *soln = new Solution();
    cout << soln->checkAlmostEquivalent(word1, word2) << endl;
    return 0;
}