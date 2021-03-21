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
        ll n; cin >> n;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool cycle = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                cycle = 1;
                break;
            }
        }
        if (n == 1) {
            cout << 0 << '\n';
        } else {
            if (cycle == 0) {
                bool imposter = 0;
                ll diff = a[1] - a[0];
                for (int i = 2; i < n; i++) {
                    if (a[i] - a[i - 1] != diff) {
                        imposter = 1; break;
                    }
                }
                cout << (imposter ? -1 : 0) << '\n';
            } else {
                bool ok = 1;
                ll diff = 1e18, reduce = 1e18;
                for (int i = 1; i < n; i++) {
                    if (a[i] - a[i - 1] >= 0) {
                        diff = a[i] - a[i - 1];
                    } else {
                        reduce = a[i - 1] - a[i];
                    }
                }
                for (int i = 1; i < n; i++) {
                    if (a[i] - a[i - 1] != diff && a[i - 1] - a[i] != reduce) {
                        ok = 0; break;
                    }
                }
                if (ok) {
                    if (diff == 1e18) {
                        cout << 0 << '\n';
                    } else {
                        bool chk = 1;
                        ll m = diff + reduce, c = diff;
                        if (a[0] >= m) chk = 0;
                        for (int i = 1; i < n; i++) {
                            if (a[i] != (a[i - 1] + c) % m || a[i] >= m) {
                                chk = 0; break;
                            }
                        }
                        if (chk) {
                            cout << m << ' ' << c << '\n';
                        } else {
                            cout << -1 << '\n';
                        }
                    }
                } else {
                    cout << -1 << '\n';
                }
            }
        }
    }
    return 0;
}