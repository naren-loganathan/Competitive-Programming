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
    int t; cin >> t;
    while (t--) {
        ll n, c; cin >> n >> c;
        vector <ll> a(n), b(n - 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        ll days = c, curr = 0, money = 0;
        for (int i = 0; i < n; i++) {
            //cout << curr + (c - money + (a[i] - 1)) / a[i] << '\n';
            days = min(days, curr + (c - money + (a[i] - 1)) / a[i]);
            if (i < n - 1) {
                ll extra = max(0LL, (b[i] - money + (a[i] - 1)) / a[i]);
                curr += extra + 1;
                money += (extra * a[i]) - b[i];
            }
        }
        cout << days << '\n';
    }
    return 0;
}