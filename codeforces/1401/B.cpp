#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int x1, y1, z1, x2, y2, z2, sum = 0;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int m = min(z1, y2);
        sum += 2 * m;
        z1 -= m;
        y2 -= m;
        m = min(z1, z2);
        z1 -= m;
        z2 -= m;
        m = min(z2, x1);
        x1 -= m;
        z2 -= m;
        m = min(z2, y1);
        sum -= 2 * m;
        cout << sum << "\n";
    }
    return 0;
}