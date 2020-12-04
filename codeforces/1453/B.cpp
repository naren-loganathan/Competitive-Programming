#include <iostream>
#include <vector>
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
        int n; cin >> n;
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll change = -1, c = -1, ci = -1, m = 0;
        for (int i = 1; i < n - 1; i++) {
            change = (a[i - 1] + a[i + 1]) / 2;
            ll diff = abs(a[i] - a[i + 1]) + abs(a[i] - a[i - 1]) - abs(a[i + 1] - change) - abs(a[i - 1] - change);
            if (diff > m) {
                c = change;
                ci = i;
                m = diff;
            }
        }
        if (abs(a[0] - a[1]) > m) {
            c = a[1];
            ci = 0;
            m = abs(a[0] - a[1]);
        }
        if (abs(a[n - 2] - a[n - 1]) > m) {
            c = a[n - 2];
            ci = n - 1;
        }
        if (ci > -1) {
            a[ci] = c;
        }
        ll sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += abs(a[i] - a[i + 1]);
        }
        cout << sum << "\n";
    }
    return 0;
}