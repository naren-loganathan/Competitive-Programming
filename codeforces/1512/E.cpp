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
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int sum = n * (n + 1) / 2, qty = r - l + 1;
        int sumi = (qty * (qty + 1)) / 2;
        vector <int> a(qty);
        for (int i = 0; i < qty; i++) {
            a[i] = i + 1;
        }
        if (s < sumi) {
            cout << -1 << '\n';
        } else {
            bool poss = 1;
            int i = qty - 1;
            while (sumi != s && i >= 0) {
                int dist = s - sumi;
                int nxt = (i == qty - 1 ? n + 1 : a[i + 1]);
                int inc = min(dist, nxt - a[i] - 1);
                a[i] += inc;
                sumi += inc;
                i -= 1;
            }
            if (sumi != s) {
                poss = 0;
            }
            /*for (int i = 0; i < qty; i++) {
                cout << a[i] << ' ';
            }
            cout << '\n';*/
            if (!poss) {
                cout << -1 << '\n';
            } else {
                set <int> ss;
                for (int i = 0; i < n; i++) ss.insert(i + 1);
                for (int i = 0; i < qty; i++) {
                    ss.erase(ss.find(a[i]));
                }
                int cnt = 0;
                for (int i = 1; i <= n; i++) {
                    if (i >= l && i <= r) {
                        cout << a[cnt] << ' ';
                        cnt++;
                    } else {
                        int val = *(ss.begin());
                        cout << val << ' ';
                        ss.erase(ss.find(val));
                    }
                }
                cout << '\n';
            }
        }
    }
    return 0;
}