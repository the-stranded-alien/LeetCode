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

// Given the head of a linked list, remove the nth node from the end of the
// list and return its head.

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertNodeAtHead(ListNode * &head, int data) {
	if(head == nullptr) {
		head = new ListNode(data);
		return;
	}
	ListNode *node = new ListNode(data);
	node->next = head;
	head = node;
	return;
}

void insertNodeInMiddle(ListNode * &head, int data, int pos) {
	if(pos == 0) insertNodeAtHead(head, data);
	else {
		ListNode *tempNode = head;
		for(int jump = 1; jump <= (pos - 1); jump++) tempNode = tempNode->next;
		ListNode *node = new ListNode(data);
		node->next = tempNode->next;
		tempNode->next = node;	
	}
	return;
}

void insertNodeAtEnd(ListNode * &head, int data) {
	if(head == nullptr) {
		head = new ListNode(data);
		return;
	}
	ListNode *node = new ListNode(data);
	ListNode *last = head;
	while(last->next != nullptr) last = last->next;
	last->next = node;
	return;
}

void printLL(ListNode * head) {
	while(head != nullptr) {
		cout << head->val << " --> ";
		head = head->next;
	}
	cout << "NULL" << nl;
	return;
}
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tempNode;
        ListNode *fp = head;
        ListNode *sp = head;
        for(int i = 0; i < n; i++) {
        	if(sp->next == nullptr) {
        		if(i == n - 1) {
        			tempNode = head;
        			head = head->next;
        			delete (tempNode);
        		}
        		return head;
        	}
        	sp = sp->next;
        }
        while(sp->next != nullptr) {
        	fp = fp->next;
        	sp = sp->next;
        }
        tempNode = fp->next;
        fp->next = fp->next->next;
        delete (tempNode);
        return head;
    }
};

void solve() {
	int n; cin >> n;
	ListNode *head = NULL;
	int data;
	while(n--) {
		cin >> data;
		insertNodeAtEnd(head, data);
	}
	int ne; cin >> ne;
	Solution *soln = new Solution();
	ListNode *newHead = soln->removeNthFromEnd(head, ne);
	printLL(newHead);
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