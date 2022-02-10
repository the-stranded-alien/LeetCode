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

// Given the head of a sorted linked list, delete all duplicates such that
// each element appears only once. Return the linked list sorted as well.

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertNodeAtHead(ListNode * &head, int val) {
	if(head == nullptr) {
		head = new ListNode(val);
		return;
	}
	ListNode *newNode = new ListNode(val);
	newNode->next = head;
	head = newNode;
	return;
}

void insertNodeInMiddle(ListNode * &head, int pos, int val) {
	if(pos == 0) insertNodeAtHead(head, val);
	else {
		ListNode *tempNode = head;
		for(int jump = 1; jump <= (pos - 1); jump++) tempNode = tempNode->next;
		ListNode *newNode = new ListNode(val);
		newNode->next = tempNode->next;
		tempNode->next = newNode;
	}
	return;
}

void insertNodeAtEnd(ListNode * &head, int val) {
	if(head == nullptr) {
		head = new ListNode(val);
		return;
	}
	ListNode *tempNode = head;
	while(tempNode->next != nullptr) tempNode = tempNode->next;
	ListNode *newNode = new ListNode(val);
	tempNode->next = newNode;
	return; 
}

void printLL(ListNode *head) {
	if(head == nullptr) return;
	while(head != nullptr) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "END" << nl;
	return;
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode *curPtr = head;
    	ListNode *nextPtr;
    	if(curPtr == nullptr) return nullptr;
    	while(curPtr->next != nullptr) {
    		if(curPtr->val == curPtr->next->val) {
    			nextPtr = curPtr->next->next;
    			delete (curPtr->next);
    			curPtr->next = nextPtr;
    		} else { curPtr = curPtr->next; }
    	}
    	return head;
    }
};

void solve() {
	// Main Code Goes Here !!
	int n; cin >> n;
	ListNode *head = nullptr;
	while(n--) {
		int val; cin >> val;
		insertNodeAtEnd(head, val);
	}
	printLL(head);
	Solution *soln = new Solution();
	ListNode *dd = soln->deleteDuplicates(head);
	printLL(dd);
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