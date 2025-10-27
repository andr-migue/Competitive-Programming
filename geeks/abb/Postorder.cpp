#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        vector<int> ans;
        aux(root, ans);
        return ans;
    }

    void aux(Node *root, vector<int> &ans)
    {
        if (root->left != NULL)
        {
            aux(root->left, ans);
        }
        if (root->right != NULL)
        {
            aux(root->right, ans);
        }
        ans.push_back(root->data);
    }
};