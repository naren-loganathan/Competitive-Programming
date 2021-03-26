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
    ll l, r; cin >> l >> r;
    vector <int> bits_l(60), bits_r(60);
    for (int i = 0; i < 60; i++) {
        if ((1LL << i) & l) bits_l[i] = 1;
        if ((1LL << i) & r) bits_r[i] = 1;
    }
    ll ans = 0;
    for (int i = 59; i >= 0; i--) {
        if ((1LL << i) & r && ((1LL << i) & l) == 0) {
            for (int j = i; j >= 0; j--) {
                ans += (1LL << j);
            }
            break;
        }
    }
    if (l == r) ans = 0;
    cout << ans << '\n';
    return 0;
}