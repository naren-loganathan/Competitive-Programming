#include <iostream>
#include <cmath>
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
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        cout << max(n - r, r - 1) + max(m - c, c - 1) << "\n"; 
    }
    return 0;
}