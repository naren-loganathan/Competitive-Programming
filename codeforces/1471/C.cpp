#include <iostream>
#include <vector>
#include <algorithm>
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
        ll n, m; cin >> n >> m;
        ll sum = 0;
        vector <ll> k(n), c(m + 1);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
        }
        sort(k.begin(), k.end(), greater <ll> ());
        int j = 1;
        for (int i = 0; i < n; i++) {
            if (c[k[i]] > c[j]) {
                //cout << "gift: " << c[j] << "\n";
                sum += c[j];
                j++;
            }
            else {
                sum += c[k[i]];
                //cout << "cash: " << c[k[i]] << "\n";
            }
        }
        cout << sum << "\n";
    }
    return 0;
}