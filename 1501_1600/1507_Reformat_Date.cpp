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

// Given a date string in the form Day Month Year, where:
// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
// Year is in the range [1900, 2100].
// Convert the date string to the format YYYY-MM-DD, where:
// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.

class Solution {
public:
	string monthIdx(string mon) {
		if(mon == "Jan") return "01";
		else if(mon == "Feb") return "02";
		else if(mon == "Mar") return "03";
		else if(mon == "Apr") return "04";
		else if(mon == "May") return "05";
		else if(mon == "Jun") return "06";
		else if(mon == "Jul") return "07";
		else if(mon == "Aug") return "08";
		else if(mon == "Sep") return "09";
		else if(mon == "Oct") return "10";
		else if(mon == "Nov") return "11";
		else if(mon == "Dec") return "12";
		else return "";
	}
    string reformatDate(string date) {
        if(date.length() == 12) {
        	char d1 = '0';
        	char d2 = date[0];
        	string mon = date.substr(4, 3);
        	string mm = monthIdx(mon);
        	string year = date.substr(8, 4);
        	return (year + "-" + mm + "-" + d1 + d2);
        } else { // length = 13
        	char d1 = date[0];
        	char d2 = date[1];
        	string mon = date.substr(5, 3);
        	string mm = monthIdx(mon);
        	string year = date.substr(9, 4);
        	return (year + "-" + mm + "-" + d1 + d2);
        }
    }
};

void solve() {
	// Main Code Goes Here !!
	string date; cin >> date;
	Solution *soln = new Solution();
	cout << soln->reformatDate(date) << nl;
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