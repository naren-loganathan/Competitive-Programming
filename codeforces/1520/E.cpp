#include <iostream>
#include <vector>
#include <string>
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
        string s; cin >> s;
        ll cnt_sheep = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') cnt_sheep++;
        }
        if (cnt_sheep == 0 || cnt_sheep == 1) {
            cout << 0 << '\n';
        } else {
            vector <ll> pre(n);
            pre[0] = (s[0] == '*' ? 1 : 0);
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + (s[i] == '*');
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == '.') {
                    ans += min(pre[i], cnt_sheep - pre[i]);
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}