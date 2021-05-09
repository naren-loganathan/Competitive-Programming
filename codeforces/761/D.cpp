#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, l, r; cin >> n >> l >> r;
    vector < pair <int, int> > a(n), b(n);
    bool poss = 1;
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].se;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        m[a[i].fi] = i;
    }
    sort(a.begin(), a.end(), greater < pair <int, int> > ());
    b[m[a[0].fi]] = mp(a[0].fi, r);
    int curr_d = r - a[0].se;
    for (int i = 1; i < n; i++) {
        int new_val = min(a[i].se + curr_d - 1, r);
        if (new_val < l) {
            poss = 0; break;
        } else {
            b[m[a[i].fi]] = mp(a[i].fi, new_val);
            curr_d = new_val - a[i].se;
        }
    }
    if (poss) {
        for (int i = 0; i < n; i++) {
            cout << b[i].se << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}