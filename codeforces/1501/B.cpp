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
        int n; cin >> n;
        vector <int> a(n), d(n + 2, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > i + 1) {
                a[i] = i + 1;
            }
            if (a[i]) {
                d[i + 2] -= 1;
                d[i + 2 - a[i]] += 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            d[i] += d[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            cout << (d[i] > 0 ? 1 : 0) << ' ';
        }
        cout << '\n';
    }
    return 0;
}