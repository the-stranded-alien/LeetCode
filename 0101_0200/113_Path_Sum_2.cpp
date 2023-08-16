#include<iostream>
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

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
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

	vector<vector<int> > paths;

	void dfs(TreeNode *root, int targetSum, vector<int> &path) {
		if(root == nullptr) return;
		path.push_back(root->val);
		targetSum -= root->val;
		if(root->left == nullptr && root->right == nullptr) {
			if(targetSum == 0) paths.push_back(path);
		} else {
			dfs(root->left, targetSum, path);
			dfs(root->right, targetSum, path);
		}
		path.pop_back();
	}

	vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
		vector<int> path;
		dfs(root, targetSum, path);
		return paths;
    }
};

void solve() {
	Solution *soln = new Solution();
	string input; cin >> input;
	TreeNode *root = buildTree(input);
	int target; cin >> target;
	// printLevelOrderWithNewLine(root);
	vector<vector<int> > paths = soln->pathSum(root, target);
	for(auto path : paths) {
		for (auto val : path) cout << val << " ";
		cout << endl;
	}
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