using System;
using System.Collections.Generic;


public class Trie
{
    private List<int[]> tree;
    private List<bool> end;
    private List<int> count;
    private int nodes;

    public Trie()
    {
        nodes = 1;
        tree = new List<int[]>();
        tree.Add(new int[52]);
        for (int i = 0; i < 52; i++)
            tree[0][i] = -1;

        end = new List<bool> { false };
        count = new List<int> { 0 };
    }

    private int GetIndex(char c)
    {
        if (c >= 'a' && c <= 'z')
            return c - 'a';
        else if (c >= 'A' && c <= 'Z')
            return c - 'A' + 26;
        else
            return -1;
    }

    public void Insert(string word)
    {
        int current = 0;

        foreach (char c in word)
        {
            int index = GetIndex(c);

            if (index < 0 || index >= 52)
                continue;

            if (tree[current][index] == -1)
            {
                tree[current][index] = nodes;

                int[] newNode = new int[52];
                for (int i = 0; i < 52; i++)
                    newNode[i] = -1;

                tree.Add(newNode);
                end.Add(false);
                count.Add(0);
                nodes++;
            }

            current = tree[current][index];
            count[current]++;
        }

        end[current] = true;
    }

    public bool Search(string word)
    {
        int current = 0;

        foreach (char c in word)
        {
            int index = GetIndex(c);

            if (index < 0 || index >= 52 || tree[current][index] == -1)
            {
                return false;
            }

            current = tree[current][index];
        }

        return end[current];
    }

    public bool StartsWith(string prefix)
    {
        int current = 0;

        foreach (char c in prefix)
        {
            int index = GetIndex(c);

            if (index < 0 || index >= 52 || tree[current][index] == -1)
            {
                return false;
            }

            current = tree[current][index];
        }

        return true;
    }

    public int CountWords(string prefix)
    {
        int current = 0;

        foreach (char c in prefix)
        {
            int index = GetIndex(c);

            if (index < 0 || index >= 52 || tree[current][index] == -1)
            {
                return 0;
            }

            current = tree[current][index];
        }

        return count[current];
    }
}

class Solution
{
    public List<string> wordBoggle(List<List<char>> board, List<string> dictionary)
    {
        Trie trie = new Trie();
        bool[,] mask = new bool[board.Count, board[0].Count];
        List<string> ans = new List<string>();
        Dictionary<string, bool> pairs = new Dictionary<string, bool>();

        int[] dirI = { 0, 0, 1, -1, 1, -1, 1, -1 };
        int[] dirJ = { 1, -1, 0, 0, 1, -1, -1, 1 };

        foreach (string s in dictionary)
        {
            trie.Insert(s);
        }

        for (int i = 0; i < board.Count; i++)
        {
            for (int j = 0; j < board[0].Count; j++)
            {
                if (trie.StartsWith(board[i][j].ToString()))
                {
                    mask[i, j] = true;

                    aux(board, trie, board[i][j].ToString(), mask, dirI, dirJ, i, j, ans, pairs);

                    mask[i, j] = false;
                }
            }
        }

        return ans;
    }

    public void aux(List<List<char>> board, Trie trie, string word, bool[,] mask, int[] dirI, int[] dirJ, int i, int j, List<string> ans, Dictionary<string, bool> pairs)
    {
        if (trie.Search(word))
        {
            if (!pairs.ContainsKey(word))
            {
                ans.Add(word);
                pairs[word] = true;
            }
        }

        for (int d = 0; d < 8; d++)
        {
            int newI = i + dirI[d];
            int newJ = j + dirJ[d];

            if (isValid(board.Count, board[0].Count, newI, newJ) && !mask[newI, newJ])
            {
                string newWord = word + board[newI][newJ];

                if (trie.StartsWith(newWord))
                {
                    mask[newI, newJ] = true;

                    aux(board, trie, newWord, mask, dirI, dirJ, newI, newJ, ans, pairs);

                    mask[newI, newJ] = false;
                }
            }
        }
    }

    bool isValid(int n, int m, int i, int j)
    {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
}