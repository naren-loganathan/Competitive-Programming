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
    int n; cin >> n;
    vector <ll> a(n), b(n);
    ll mat[n][n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = a[i] * b[j];
        }
        ans += mat[i][i];
    }
    ll add = 0;
    for (int d = 0; d < n; d++) {
        ll curr1 = mat[d][d], curr2 = mat[d][d];
        for (int inc = 1; inc <= min(d, n - 1 - d); inc++) {
            curr1 += (mat[d + inc][d + inc] + mat[d - inc][d - inc]);
            curr2 += (mat[d + inc][d - inc] + mat[d - inc][d + inc]);
            add = max(add, curr2 - curr1);
        }
    }
    for (int d = 1; d < n; d++) {
        ll curr1 = mat[d][d] + mat[d - 1][d - 1];
        ll curr2 = mat[d][d - 1] + mat[d - 1][d];
        add = max(add, curr2 - curr1);
        for (int inc = 1; inc <= min(d - 1, n - 1 - d); inc++) {
            curr1 += (mat[d - 1 - inc][d - 1 - inc] + mat[d + inc][d + inc]);
            curr2 += (mat[d + inc][d - 1 - inc] + mat[d - 1 - inc][d + inc]);
            add = max(add, curr2 - curr1);
        }
    }
    cout << ans + add << '\n';
    return 0;
}