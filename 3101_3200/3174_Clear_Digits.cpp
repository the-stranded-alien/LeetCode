#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;

// You are given a string s.
// Your task is to remove all digits by doing this operation repeatedly:
// Delete the first digit and the closest non-digit character to its left.
// Return the resulting string after removing all digits.
// Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.

class Solution {
private:
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }    
    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z');
    }
public:
    string clearDigits(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty()) st.push(c);
            else {
                char stElement = st.top();
                if (isLetter(stElement) && isDigit(c)) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        return string(result.rbegin(), result.rend());
    }
};

int main() {
    string s; cin >> s;
    Solution *soln = new Solution();
    cout << soln->clearDigits(s) << endl;
    return 0;
}