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
    int minValue(Node *root)
    {
        if (root->left == NULL)
        {
            return root->data;
        }

        return minValue(root->left);
    }
};