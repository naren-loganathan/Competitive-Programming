#include <iostream>
#include <string>
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
        string s; cin >> s;
        bool ok = 0;
        int n = s.length();
        vector <int> zero(n, 0), one(n, 0), b0(n, 0), b1(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i == 0) {
                    b0[0] = 1;
                    zero[i] = 1;
                } else {
                    if (b0[i - 1]) {
                        break;
                    } else {
                        b0[i] = 1;
                        zero[i] = 1;
                    }
                }
            } else {
                zero[i] = 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                if (i == n - 1) {
                    b1[n - 1] = 1;
                    one[i] = 1;
                } else {
                    if (b1[i + 1]) {
                        break;
                    } else {
                        b1[i] = 1;
                        one[i] = 1;
                    }
                }
            } else {
                one[i] = 1;
            }
        }
        if (zero[n - 1] || one[0]) {
            ok = 1;
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (zero[i] && one[i + 1] && (!b0[i] || !b1[i + 1])) {
                    ok = 1; break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}