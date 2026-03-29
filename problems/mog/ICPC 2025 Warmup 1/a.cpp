#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class DisjointSet {
public:
    void make_set(string s) {
        parent[s] = s;
        sz[s] = 1;
    }

    string find_set(string s) {
        if (s == parent[s])
            return s;

        return parent[s] = find_set(parent[s]);
    }

    int union_set(string a, string b) {
        a = find_set(a);
        b = find_set(b);

        if (a == b)
            return sz[a];

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return sz[a];
    }

private:
    map<string, string> parent;
    map<string, int> sz;
};

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int m;
        cin >> m;

        set<string> people;
        vector<pair<string, string>> friends;

        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;

            people.insert(a);
            people.insert(b);

            friends.push_back({a, b});
        }

        DisjointSet dsu;
        for (string p: people) {
            dsu.make_set(p);
        }

        for (auto f: friends) {
            cout << dsu.union_set(f.first, f.second) << "\n";
        }
    }

    return 0;
}