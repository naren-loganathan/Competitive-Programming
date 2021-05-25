#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector < vector <int> > p(n, vector <int> (3));
    map <int, vector <int> > mz;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> p[i][j];
        }
        mz[p[i][2]].push_back(i);
    }
    vector <int> rem_z;
    map <int, vector <int> > :: iterator it1, it2;
    for (it1 = mz.begin(); it1 != mz.end(); it1++) {
        vector <int> rem_y;
        map <int, vector <int> > my;
        vector <int> v = it1 -> se;
        for (int i = 0; i < v.size(); i++) {
            my[p[v[i]][1]].push_back(v[i]);
        }
        for (it2 = my.begin(); it2 != my.end(); it2++) {
            vector <int> w = it2 -> se;
            vector < pair <int, int> > x;
            for (int i = 0; i < w.size(); i++) {
                x.push_back(mp(p[w[i]][0], w[i]));
            }
            sort(x.begin(), x.end());
            for (int i = 0; i + 1 < x.size(); i += 2) {
                cout << x[i].se + 1 << ' ' <<  x[i + 1].se + 1 << '\n';
            }
            if (x.size() % 2) {
                rem_y.push_back(x.back().se);
            }
        }
        for (int i = 0; i + 1 < rem_y.size(); i += 2) {
            cout << rem_y[i] + 1 << ' ' <<  rem_y[i + 1] + 1 << '\n';
        }
        if (rem_y.size() % 2) {
            rem_z.push_back(rem_y.back());
        }
    }
    for (int i = 0; i + 1 < rem_z.size(); i += 2) {
        cout << rem_z[i] + 1 << ' ' << rem_z[i + 1] + 1 << '\n';
    }
    return 0;
}