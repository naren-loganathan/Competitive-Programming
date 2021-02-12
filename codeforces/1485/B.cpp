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
    ll n, q, k; cin >> n >> q >> k;
    vector <ll> a(n), shift(n), p_shift(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            shift[i] = a[0] - 1;
        }
        else if (i == n - 1) {
            shift[i] = k - n;
        }
        else {
            shift[i] = a[i + 1] - a[i - 1] - 2;
        }
    }
    for (int i = 0; i < n; i++) {
        p_shift[i] = (i ? p_shift[i - 1] + shift[i] : shift[i]);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        ll answer = 0;
        if (l == r) {
            answer = k - 1;
        }
        else if (r - l == 1) {
            answer = k - a[r] + a[l] - 1 + 2 * (a[r] - a[l] - 1);
        }
        else {
            answer = k - a[r] + a[l] - 1 + a[r] - a[r - 1] - 1 + a[l + 1] - a[l] - 1 + p_shift[r - 1] - p_shift[l];
        }
        cout << answer << "\n";
    }
    return 0;
}