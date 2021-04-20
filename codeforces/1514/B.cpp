#include <iostream>
#include <vector>
#include <cmath>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k, ans = 1; 
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            ans = (ans * n) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}