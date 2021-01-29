#include <iostream>
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
        ll a = n / k + (n % k ? 1 : 0);
        k *= a;
        cout << k / n + (k % n ? 1 : 0) << "\n";
    }
    return 0;
}
