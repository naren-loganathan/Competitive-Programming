#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
        ll n; cin >> n;
        vector <ll> u(n / 2), min_u(n / 2), pu(n / 2);
        ll size_r = n / 2 + (n % 2);
        vector <ll> r(size_r), min_r(size_r), pr(size_r);
        for (int i = 0; i < n; i++) {
            ll c; cin >> c;
            if (i % 2) {
                u[i / 2] = c;
                pu[i / 2] = c;
                if (i / 2) {
                    pu[i / 2] += pu[i / 2 - 1];
                }
            } else {
                r[i / 2] = c;
                pr[i / 2] = c;
                if (i / 2) {
                    pr[i / 2] += pr[i / 2 - 1];
                }
            }
        }
        for (int i = 0; i < n / 2; i++) {
            min_u[i] = (i ? min(u[i], min_u[i - 1]) : u[i]);
        } 
        for (int i = 0; i < size_r; i++) {
            min_r[i] = (i ? min(r[i], min_r[i - 1]) : r[i]);
        }
        ll cost = 1e18, itu = n / 2 - 1, itr = size_r - 1;
        bool rgt = 1;
        if (itr == itu) {
            rgt = 0;
        }
        while (itu >= 0 && itr >= 0) {
            ll cmp = pr[itr] + pu[itu];
            cmp += min_r[itr] * (n - itr - 1LL);
            cmp += min_u[itu] * (n - itu - 1LL);
            cost = min(cost, cmp);
            (rgt ? itr -= 1 : itu -= 1);
            if (rgt == 1) {
                rgt = 0;
            } else {
                rgt = 1;
            }
        }
        cout << cost << '\n';
    }
    return 0;
}