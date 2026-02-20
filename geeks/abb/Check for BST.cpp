#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool isBST(Node *root)
    {
        return aux(root, INT_MIN, INT_MAX);
    }

    bool aux(Node *root, int min, int max)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->data <= min || root->data >= max)
        {
            return false;
        }

        return aux(root->left, min, root->data) && aux(root->right, root->data, max);
    }
};