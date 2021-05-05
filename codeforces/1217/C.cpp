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
        int n = s.length(), cnt0 = 0, ans = 0;
        vector <int> zb(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt0 += 1;
            } else {
                zb[i] = cnt0;
                cnt0 = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int num = 1, len = 1, j = i + 1;
                while (true) {
                    if (num <= len + zb[i]) {
                        ans += 1;
                        if (j < n) {
                            num = 2 * num + (s[j] - '0');
                            len += 1;
                            j += 1;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}