#include <iostream>
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
        int a, b; cin >> a >> b;
        string s; cin >> s;
        int n = a + b;
        int cnt0 = a, cnt1 = b;
        bool poss = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (s[n - 1 - i] == '1') {
                    poss = 0; break;
                }
                s[n - 1 - i] = '0';
            } else if (s[i] == '1') {
                if (s[n - 1 - i] == '0') {
                    poss = 0; break;
                }
                s[n - 1 - i] = '1';
            }
        }
        if (poss) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    a--;
                } else if (s[i] == '1') {
                    b--;
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == '?') {
                    if (n % 2 && i == (n + 1) / 2 - 1) {
                        if (a % 2) {
                            s[i] = '0'; a--;
                        } else if (b % 2) {
                            s[i] = '1'; b--;
                        } else {
                            poss = 0; break;
                        }
                    } else {
                        if (a > 1) {
                            s[i] = '0'; s[n - 1 - i] = '0'; a -= 2;
                        } else if (b > 1) {
                            s[i] = '1'; s[n - 1 - i] = '1'; b -= 2;
                        } else {
                            poss = 0; break;
                        }
                    }
                    if (a < 0 || b < 0) {
                        poss = 0; break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] != s[n - 1 - i]) {
                    poss = 0; break;
                }
                if (s[i] == '1') cnt1--;
                if (s[i] == '0') cnt0--;
            }
            if (cnt1 != 0 || cnt0 != 0) {
                poss = 0;
            }
        }
        if (poss) {
            cout << s << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}