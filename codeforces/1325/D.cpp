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
    ll u, v; cin >> u >> v;
    if (u > v || (v - u) % 2) {
        cout << -1 << '\n';
    } else {
        vector <ll> ans(3);
        ans[0] = u;
        v -= u;
        for (int i = 59; i > 0; i--) {
            if ((1LL << i) & v) {
                int cnt = 0;
                for (int j = 0; j < 3 && cnt < 2; j++) {
                    if (((1LL << (i - 1)) & ans[j]) == 0) {
                        ans[j] += (1LL << (i - 1)); cnt += 1;
                    }
                }
            }
        }
        for (int i = 2; i >= 0; i--) {
            if (ans.back() == 0) {
                ans.pop_back();
            }
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}