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
        ll n, m, x; cin >> n >> m >> x;
        ll col = (x - 1) / n + 1, row = (x % n);
        if (row == 0) row = n;
        cout << m * (row - 1) + col << '\n';
    }
    return 0;
}