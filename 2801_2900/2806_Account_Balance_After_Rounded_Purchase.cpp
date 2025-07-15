#include<bits/stdc++.h>
#include<iostream>

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

// Initially, you have a bank account balance of 100 dollars.

// You are given an integer purchaseAmount representing the amount you will spend on a purchase in dollars, in other words, its price.

// When making the purchase, first the purchaseAmount is rounded to the nearest multiple of 10. Let us call this value roundedAmount. Then, roundedAmount dollars are removed from your bank account.

// Return an integer denoting your final bank account balance after this purchase.

// Notes:

// 0 is considered to be a multiple of 10 in this problem.
// When rounding, 5 is rounded upward (5 is rounded to 10, 15 is rounded to 20, 25 to 30, and so on).

class Solution {
public:
	int accountBalanceAfterPurchase(int purchaseAmount) {
		if(purchaseAmount == 100) return 0;
        int initialBalance = 100;
        if(purchaseAmount == 0) return initialBalance;

        int firstPlaceDigit = purchaseAmount % 10;
        int secondPlaceDigit = (purchaseAmount / 10) % 10;
        if(firstPlaceDigit == 0) {
        	return initialBalance - purchaseAmount;
        }
        else if(firstPlaceDigit >= 1 && firstPlaceDigit <= 4) {
        	return initialBalance - (10 * secondPlaceDigit);
        }
        else {
        	return initialBalance - (10 * (secondPlaceDigit + 1));
        }
    }
};

void solve() {
	// Main Code Goes Here !!
	int amt; cin >> amt;
	
	Solution *soln = new Solution();
	cout << soln->accountBalanceAfterPurchase(amt);

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