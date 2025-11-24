using System;
using System.Collections.Generic;

namespace geeks
{
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

}
