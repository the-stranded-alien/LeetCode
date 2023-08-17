#include<iostream>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeFromLevelOrder(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int index = 1;
    while (!q.empty() && index < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[index] != "null") {
            current->left = new TreeNode(stoi(nodes[index]));
            q.push(current->left);
        }
        index++;

        if (index < nodes.size() && nodes[index] != "null") {
            current->right = new TreeNode(stoi(nodes[index]));
            q.push(current->right);
        }
        index++;
    }

    return root;
}

TreeNode* buildTree(string input) {
    vector<string> nodes;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        nodes.push_back(token);
    }

    return buildTreeFromLevelOrder(nodes);
}

void printLevelOrderWithNewLine(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();

            if (current != nullptr) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    	if(root == nullptr || subRoot == nullptr) return false;
    	if(isSameTree(root, subRoot)) return true;
    	return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

void solve() {
	Solution *soln = new Solution();
	string s1; cin >> s1;
	TreeNode *root = buildTree(s1);
	string s2; cin >> s2;
	TreeNode *subRoot = buildTree(s2);
	cout << soln->isSubtree(root, subRoot);
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