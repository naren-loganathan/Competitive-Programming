#include <iostream>
#include <vector>
#include <algorithm>
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
        int n, m, x;
        cin >> n >> m >> x;
        vector <int> a(n), curr(m);
        vector < pair <int, int> > h(n);
        for (int i = 0; i < n; i++) {
            int height; cin >> height;
            h[i] = mp(height, i);
        }
        sort(h.begin(), h.end());
        int itr1 = n - 1, itr2 = 0;
        bool right = 1;
        while (itr1 >= 0) {
            a[h[itr1].se] = itr2 + 1;
            curr[itr2] += h[itr1].fi;
            itr2 += (right ? 1 : -1);
            if (itr2 >= m) {
                right = 0; itr2 = m - 1;
            } else if (itr2 < 0) {
                right = 1; itr2 = 0;
            }
            itr1 -= 1;
        }
        /*for (int i = 0; i < m; i++) {
            cout << curr[i] << ' ';
        }
        cout << '\n';*/
        int d = *max_element(curr.begin(), curr.end()) - *min_element(curr.begin(), curr.end());
        if (d > x) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}