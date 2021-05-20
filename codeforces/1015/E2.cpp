#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

// Disgusting. :(

template <typename T>
struct Fenwick {
    const int n; vector <T> tree;
    Fenwick(int n) : n(n), tree(n) {}
    void update(int x, T v) {
        for (int i = x; i < n; i = (i | (i + 1))) {
            tree[i] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ans += tree[i];
        }
        return ans;
    }
    void range_update(int l, int r, T v) {
        update(l, v);
        if (r + 1 < n) {
            update(r + 1, -v);
        }
    }
    T point_query(int x) {
        return sum(x);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <int> x, y, s;
    int n, m, lo, hi; 
    cin >> n >> m;
    vector <string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector < vector < pair <int, int> > > hor(n), ver(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                int start = j;
                while (j < m && grid[i][j] == '*') j += 1;
                int end = j - 1;
                hor[i].push_back(mp(start, end));
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '*') {
                int start = i;
                while (i < n && grid[i][j] == '*') i += 1;
                int end = i - 1;
                ver[j].push_back(mp(start, end));
            }
        }
    }
    vector < Fenwick <int> > h_trees(n, Fenwick <int> (m)), v_trees(m, Fenwick <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                // cout << "Point: " << i << ' ' << j << '\n';
                int size = 500;
                lo = 0, hi = hor[i].size() - 1;
                while (lo < hi) {
                    int mid = (lo + hi) >> 1;
                    if (hor[i][mid].fi <= j && j <= hor[i][mid].se) {
                        lo = mid; hi = mid;
                    } else if (j < hor[i][mid].fi) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                // cout << "Horizontal segment: " << hor[i][lo].fi << ' ' << hor[i][lo].se << '\n';
                size = min(size, min(j - hor[i][lo].fi, hor[i][lo].se - j));
                lo = 0, hi = ver[j].size() - 1;
                while (lo < hi) {
                    int mid = (lo + hi) >> 1;
                    if (ver[j][mid].fi <= i && i <= ver[j][mid].se) {
                        lo = mid; hi = mid;
                    } else if (i < ver[j][mid].fi) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                }
                // cout << "Vertical segment: " << ver[j][lo].fi << ' ' << ver[j][lo].se << '\n';
                size = min(size, min(i - ver[j][lo].fi, ver[j][lo].se - i));
                if (size) {
                    x.push_back(i); y.push_back(j); s.push_back(size);
                    h_trees[i].range_update(j - size, j + size, 1);
                    v_trees[j].range_update(i - size, i + size, 1);
                }
            }
        }
    }
    bool poss = true;
    for (int i = 0; i < n && poss; i++) {
        for (int j = 0; j < m && poss; j++) {
            if (grid[i][j] == '*') {
                if (h_trees[i].point_query(j) == 0 && v_trees[j].point_query(i) == 0) {
                    poss = 0;
                }
            }
        }
    }
    if (poss) {
        cout << x.size() << '\n';
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << s[i] << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
    return 0;
}