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
        ll n, k; cin >> n >> k;
        vector <int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        int days = 1e9;
        for (int i = 1; i <= 100; i++) {
            int j = 0, d = 0;
            while (j < n) {
                if (c[j] != i) {
                    d++; j += k;
                }
                else {
                    j++;
                }
            }
            days = min(d, days);
        }
        cout << days << "\n";
    }
    return 0;
}