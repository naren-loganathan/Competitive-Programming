#include <iostream>
#include <cmath>
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
        ll n, a, b;
        cin >> n >> a >> b;
        string s; cin >> s;
        ll cost = b * (n + 1) + a * n;
        int i = 0, j = n - 1;
        while (s[i] != '1' && i < n) i += 1;
        while (s[j] != '1' && j >= 0) j -= 1;
        if (i != n) {
            int cross_cnt = 2, len0 = 0, len1 = 0;
            for (int k = i; k <= j; k++) {
                if (s[k] == '0') {
                    len0 += 1;
                    if (len1) {
                        cost += b * (len1 + 1);
                        len1 = 0;
                    }
                }
                else {
                    len1 += 1;
                    if (len0) {
                        if (len0 != 1) {
                            if (2 * a > (len0 - 1) * b) {
                                cost += (len0 - 1) * b;
                            }
                            else {
                                cross_cnt += 2;
                            }
                        }
                        len0 = 0;
                    }
                }
            }
            cost += a * cross_cnt + b * (len1 + 1);
        }
        cout << cost << '\n';
    }
    return 0;
}