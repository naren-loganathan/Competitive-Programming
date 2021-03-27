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
        int n; cin >> n;
        vector <int> q(n), lmin(n), lmax(n);
        set <int> min_fill, max_fill;
        for (int i = 0; i < n; i++) {
            cin >> q[i];
            min_fill.insert(i + 1);
            max_fill.insert(i + 1);
        }
        lmin[0] = q[0]; lmax[0] = q[0];
        min_fill.erase(q[0]);
        max_fill.erase(q[0]);
        for (int i = 1; i < n; i++) {
            if (q[i] != q[i - 1]) {
                lmin[i] = q[i];
                lmax[i] = q[i];
                min_fill.erase(q[i]);
                max_fill.erase(q[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (lmin[i] == 0) {
                lmin[i] = *(min_fill.begin());
                min_fill.erase(lmin[i]);
            }
        }
        int ub = 0;
        for (int i = 0; i < n; i++) {
            if (lmax[i]) {
                ub = lmax[i];
            } else {
                int val = 0;
                set <int> :: iterator it;
                it = max_fill.lower_bound(ub);
                if (it == max_fill.end()) {
                    val = *(max_fill.rbegin());
                } else {
                    it--;
                    val = *it;
                }
                lmax[i] = val;
                max_fill.erase(val);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << lmin[i] << ' ';
        }
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << lmax[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}