#include <iostream>
#include <vector>
#include <set>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        bool possible = 1;
        int n, m, garbage = 0; cin >> n >> m;
        vector < vector <int> > indices(n + 1);
        vector <int> a(n), b(n), c(m), okay(m);
        set <int> b_colours;
        multiset <int> req;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b_colours.insert(b[i]);
            if (a[i] != b[i]) {
                indices[b[i]].push_back(i + 1);
                req.insert(b[i]);
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }
        if (b_colours.find(c.back()) == b_colours.end()) {
            possible = 0;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (b[i] == c.back()) {
                    garbage = i + 1;
                    if (a[i] != b[i]) {
                        break;
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                int idx = 0;
                if (req.find(c[i]) != req.end()) {
                    idx = indices[c[i]].back();
                    indices[c[i]].pop_back();
                    req.erase(req.find(c[i]));
                }
                else {
                    idx = garbage;
                }
                okay[i] = idx;
            }
        }
        if (!possible || req.size()) {
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
            for (int i = 0; i < m; i++) {
                cout << okay[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}