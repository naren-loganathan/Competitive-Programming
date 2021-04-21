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
    ll r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;
    ll d = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
    d = ceil(sqrt(d));
    cout << (d + (2 * r) - 1) / (2 * r) << '\n';
    return 0;
}