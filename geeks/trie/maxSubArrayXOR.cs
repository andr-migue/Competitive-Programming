using System;

public class Node
{
    public int value;
    public Node[] arr = new Node[2];
    public Node()
    {
        value = 0;
        arr[0] = null!;
        arr[1] = null!;
    }
}

public class BinaryTrie
{
    private const int n = 32;
    public Node root;

    public BinaryTrie()
    {
        root = new Node();
    }

    public void Insert(int number)
    {
        Node temp = root;

        for (int i = n - 1; i >= 0; i--)
        {
            int value = (number & (1 << i)) >= 1 ? 1 : 0;

            if (temp.arr[value] == null)
            {
                temp.arr[value] = new Node();
            }

            temp = temp.arr[value];
        }

        temp.value = number;
    }

    public int Query(int number)
    {
        Node temp = root;

        for (int i = n - 1; i >= 0; i--)
        {

            int val = (number & (1 << i)) >= 1 ? 1 : 0;

            if (temp.arr[1 - val] != null)
            {
                temp = temp.arr[1 - val];
            }

            else if (temp.arr[val] != null)
            {
                temp = temp.arr[val];
            }
        }

        return number ^ temp.value;
    }
}

class SolutionMaxSubarrayXOR
{
    public int maxSubarrayXOR(int N, int[] arr)
    {
        if (N == 0)
        {
            return 0;
        }

        BinaryTrie trie = new BinaryTrie();

        int ans = 0;
        int pre_xor = 0;

        trie.Insert(0);

        for (int i = 0; i < N; i++)
        {
            pre_xor = pre_xor ^ arr[i];
            int current = trie.Query(pre_xor);
            ans = Math.Max(ans, current);

            trie.Insert(pre_xor);
        }

        return ans;
    }
}