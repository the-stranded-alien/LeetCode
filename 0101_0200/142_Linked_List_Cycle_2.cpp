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

// Given the head of a linked list, return the node where the cycle begins.
// If there is no cycle, return null. There is a cycle in a linked list if
// there is some node in the list that can be reached again by continuously
// following the next pointer. Internally, pos is used to denote the index of
// the node that tail's next pointer is connected to (0-indexed). It is -1 if
// there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void insertAtHead(ListNode * &head, int data) {
    if(head == NULL) {
        head = new ListNode(data);
        return;
    }
    // Otherwise
    ListNode *node = new ListNode(data);
    node->next = head;
    head = node;
    return;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast && fast->next) {
        	slow = slow->next;
        	fast = fast->next->next;
        	if(slow == fast) break;
        }
        if(!(fast && fast->next)) return NULL;
        while(head != slow) {
        	head = head->next;
        	slow = slow->next;
        }
        return head;
    }
};


void solve() {
	// Main Code Goes Here !!
	int n;
	cin >> n;
	vi temp(n, 0);
	for(int i = 0; i < n; i++) cin >> temp[i];
	reverse(temp.begin(), temp.end());
	ListNode *head = NULL;
	for(int i = 0; i < n; i++) insertAtHead(head, temp[i]);
	head->next = head; // To make a loop
	Solution *soln = new Solution();
	ListNode* cycleNode = soln->detectCycle(head);
	if(cycleNode == NULL) cout << "no cycle" << nl;
	// Printing Value Instead of Index Here !
	else cout << "tail connects to node index " << cycleNode->val << nl;
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