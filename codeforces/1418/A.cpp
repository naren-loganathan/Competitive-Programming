#include <iostream>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll x, y, k, trades;
        cin >> x >> y >> k; 
        trades = (k * (y + 1) - 1) / (x - 1) + k;
        if ((k * (y + 1) - 1) % (x - 1)) {
            trades++;
        }
        cout << trades << "\n";
    }
    return 0;
}