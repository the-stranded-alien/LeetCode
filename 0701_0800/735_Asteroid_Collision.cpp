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

// We are given an array asteroids of integers representing asteroids in a row.
// For each asteroid, the absolute value represents its size, and the sign
// represents its direction (positive meaning right, negative meaning left). Each
// asteroid moves at the same speed. Find out the state of the asteroids after all
// collisions. If two asteroids meet, the smaller one will explode. If both are the
// same size, both will explode. Two asteroids moving in the same direction will never meet.

// def asteroidCollision(self, asteroids):
//     ans = [-1]
//     for new in asteroids:
//         while new < 0 < ans[-1]:
//             if -new < ans[-1] or -new == ans.pop():
//                 break
//         else:
//             ans.append(new)
//     return ans[1:]

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto i : asteroids){
            if(i > 0) st.push(i);
            else{
                while((st.size() > 0) && (st.top() > 0) && (st.top() < -i)) st.pop();
                if((st.size() > 0) && (st.top() == -i)) st.pop();
                else if((st.size() > 0) && (st.top() > -i)) { continue; } //no neeed to do anything.
                else st.push(i); // Stack Is Empty
            }
        }        
        int n = st.size();
        vector<int> ans(n, 0);
        int itr = (n - 1);
        while(!st.empty()) {
        	ans[itr--] = st.top();
            st.pop();
        }
        return ans;
    }
};

void solve() {
	// Main Code Goes Here !!
	int ast; cin >> ast;
	vector<int> asteroids(ast, 0);
	for(int i = 0; i < ast; i++) cin >> asteroids[i];
	Solution *soln = new Solution();
	vi afterCollision = soln->asteroidCollision(asteroids);
	for(auto asteroid : afterCollision) cout << asteroid << " ";
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