#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// insert to binary tree
TreeNode* insert(TreeNode* root, int val) {
    if(root == nullptr) return new TreeNode(val);
    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// inorder traversal of binary tree
TreeNode* inorder(TreeNode* root) {
    if(root == nullptr) return nullptr;
    root->left = inorder(root->left);
    cout << root->val << " ";
    root->right = inorder(root->right);
    return root;
}

//get the minimum value in the binary tree
TreeNode* minValue(TreeNode* root) {
    if(root == nullptr) return nullptr;
    while(root->left != nullptr) root = root->left;
    return root;
}

//get the maximum value in the binary tree
int maxValue(TreeNode* root) {
    if(root == nullptr) return INT_MIN;
    while(root->right != nullptr) root = root->right;
    return root->val;
}

//delete a node from the binary tree

TreeNode* deleteNode(TreeNode* root, int val) {
    if(root == nullptr) return nullptr;
    if(val < root->val) root->left = deleteNode(root->left, val);
    else if(val > root->val) root->right = deleteNode(root->right, val);
    else {
        if(root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = minValue(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

//get height of the binary tree
int height(TreeNode* root) {
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

//count leaves in the binary tree
int countLeaves(TreeNode* root) {
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}



//graphical representation of the binary tree
void printTree(TreeNode* root) {
    if(root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == nullptr) {
            cout << endl;
            if(!q.empty()) q.push(nullptr);
        }
        else {
            cout << temp->val << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}


int main(int argc, const char** argv) {

    TreeNode* root = NULL;
    root = insert(root, -1);
    root = insert(root, 3);
    root = insert(root, -15);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 7);
    // deleteNode(root, 8);
    // inorder(root);
 
    cout<< maxValue(root) << endl;
    cout<< minValue(root) << endl;
    
    // cout<< height(root) << endl;

    // printTree(root);
    
    return 0;
}
