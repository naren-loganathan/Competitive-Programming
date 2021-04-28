#include <iostream>
#include <set>
#include <vector>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    vector <ll> res(n), present(n);
    ll a[n][n], x[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i]; x[i]--;
    }
    for (int k = n - 1; k >= 0; k--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = min(a[i][j], a[i][x[k]] + a[x[k]][j]);
            }
        }
        present[x[k]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (present[i] && present[j]) {
                    res[k] += a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}