#include <bits/stdc++.h>
#include <tuple>
#include <unordered_map>

using namespace std;

namespace structures 
{
    typedef priority_queue<int, vector<int>, greater<int>> minHeap;
    typedef priority_queue<int> maxHeap;
    
    class indexed_minheap
    {
        vector<int> heap;
        unordered_map<int, int> index;

        void swap_nodes(int i, int j) 
        {
            swap(heap[i], heap[j]);
            index[heap[i]] = i;
            index[heap[j]] = j;
        }

        void sift_up(int i) 
        {
            while (i > 0) 
            {
                int p = (i - 1) / 2;

                if (heap[p] <= heap[i]) break;

                swap_nodes(i, p);
                i = p;
            }
        }

        void sift_down(int i) 
        {
            int n = (int)heap.size();

            while (true) 
            {
                int l = 2*i + 1, r = 2*i + 2, best = i;

                if (l < n && heap[l] < heap[best]) best = l;
                if (r < n && heap[r] < heap[best]) best = r;
                if (best == i) break;

                swap_nodes(i, best);
                i = best;
            }
        }
    public:
        bool empty() const { return heap.empty(); }
        bool contains(int x) const { return index.find(x) != index.end(); }

        void push(int x) 
        {
            if (contains(x)) return;

            index[x] = (int)heap.size();
            heap.push_back(x);
            sift_up((int)heap.size() - 1);
        }

        int top() const { return heap.front(); }

        void pop() { erase(heap.front()); }

        void erase(int x) 
        {
            auto it = index.find(x);

            if (it == index.end()) return;

            int i = it->second;
            int last = (int)heap.size() - 1;

            if (i != last) swap_nodes(i, last);

            index.erase(heap.back());
            heap.pop_back();

            if (i < (int)heap.size()) 
            {
                sift_up(i);
                sift_down(i);
            }
        }
    };

    class indexed_ponderaded_minheap
    {
        struct pair_hash
        {
            size_t operator()(const pair<int, int>& p) const
            {
                return (static_cast<size_t>(static_cast<unsigned int>(p.first)) << 32)
                     ^ static_cast<size_t>(static_cast<unsigned int>(p.second));
            }
        };

        vector<tuple<int, int, int>> heap;                   // <w, u, v>
        unordered_map<pair<int, int>, int, pair_hash> index; // <<u, v>, index>

        pair<int, int> edge_key(int u, int v) const
        {
            if (u > v) swap(u, v);
            return {u, v};
        }

        void swap_nodes(int i, int j) 
        {
            swap(heap[i], heap[j]);

            auto [w1, u1, v1] = heap[i];
            auto [w2, u2, v2] = heap[j];

            index[edge_key(u1, v1)] = i;
            index[edge_key(u2, v2)] = j;
        }

        void sift_up(int i) 
        {
            while (i > 0) 
            {
                int p = (i - 1) / 2;

                if (heap[p] <= heap[i]) break;

                swap_nodes(i, p);
                i = p;
            }
        }

        void sift_down(int i) 
        {
            int n = (int)heap.size();

            while (true) 
            {
                int l = 2*i + 1, r = 2*i + 2, best = i;

                if (l < n && heap[l] < heap[best]) best = l;
                if (r < n && heap[r] < heap[best]) best = r;
                if (best == i) break;

                swap_nodes(i, best);
                i = best;
            }
        }
    public:
        bool empty() const 
        { 
            return heap.empty(); 
        }

        bool contains(tuple<int, int> edge) const 
        {
            auto [u, v] = edge;
            return index.find(edge_key(u, v)) != index.end(); 
        }

        void push(tuple<int, int, int> edge) 
        {
            auto [w, u, v] = edge;
            
            if (contains({u, v})) return;

            index[edge_key(u, v)] = (int)heap.size();
            heap.push_back(edge);
            sift_up((int)heap.size() - 1);
        }

        tuple<int, int, int> top() const { return heap.front(); }

        void pop() 
        { 
            erase(heap.front()); 
        }

        void erase(tuple<int, int, int> x) 
        {
            auto [w, u, v] = x;
            auto it = index.find(edge_key(u, v));

            if (it == index.end()) return;

            int i = it->second;
            int last = (int)heap.size() - 1;

            if (i != last) swap_nodes(i, last);

            auto [lw, lu, lv] = heap.back();
            index.erase(edge_key(lu, lv));
            heap.pop_back();

            if (i < (int)heap.size()) 
            {
                sift_up(i);
                sift_down(i);
            }
        }
    };

    class online_median
    {
    private:
        maxHeap left;
        minHeap right;

        void balance()
        {
            if (left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }
            else if (right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
        }

    public:
        void insert(int x)
        {
            if (left.empty() || x <= left.top())
                left.push(x);
            else
                right.push(x);

            balance();
        }

        int median()
        {
            return left.top();
        }

        double medianDouble()
        {
            if (left.size() > right.size())
                return left.top();
            return (left.top() + right.top()) / 2.0;
        }
    };
}