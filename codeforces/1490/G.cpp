#include <iostream>
#include <vector>
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
        ll n, m, x; cin >> n >> m;
        vector <ll> a(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = a[i] + (i ? p[i - 1] : 0);
        }
        vector < pair <ll, ll> > mx;
        mx.push_back(mp(p[0], 1));
        for (int i = 1; i < n; i++) {
            if (p[i] > mx.back().fi) {
                mx.push_back(mp(p[i], i + 1));
            }
        }
        while (m--) {
            cin >> x;
            ll answer = -1;
            if (x <= mx.back().fi || p.back() > 0) {
                answer = 0;
                if (x > mx.back().fi) {
                    ll q = ((x - mx.back().fi + p.back() - 1) / p.back());
                    answer += n * q;
                    x -= p.back() * q;
                }
                int l = 0, r = mx.size() - 1, mid = 0;
                while (l < r) {
                    mid = (l + r) >> 1;
                    if (mx[mid].fi == x) {
                        l = mid; r = mid;
                    }
                    else if (mx[mid].fi < x) {
                        l = mid + 1;
                    }
                    else {
                        r = mid;
                    }
                }
                answer += mx[l].se - 1;
            }
            cout << answer << " ";
        }
        cout << "\n";
    }
    return 0;
}