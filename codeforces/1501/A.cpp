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
        ll n; cin >> n;
        vector <ll> a(n), b(n), t(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
        ll time = t[0] + a[0];
        for (int i = 0; i < n - 1; i++) {
            time += (b[i] - a[i] + 1) / 2;
            if (time < b[i]) {
                time = b[i];
            }
            time += (t[i + 1] + a[i + 1] - b[i]);
        }
        cout << time << '\n';
    }
    return 0;
}