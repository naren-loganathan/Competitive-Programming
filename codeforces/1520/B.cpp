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
        ll n, ans = 0; 
        cin >> n;
        ll x = n, num_digits = 0;
        while (x) {
            num_digits += 1;
            x /= 10;
        }
        ans += 9 * (num_digits - 1);
        for (int i = 1; i < 10; i++) {
            string s = "";
            for (int j = 0; j < num_digits; j++) {
                s += ('0' + i);
            }
            ll x = stoll(s);
            if (x <= n) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}