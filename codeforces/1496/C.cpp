#include <iostream>
#include <set>
#include <cmath>
using namespace std;
     
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        multiset <int, greater <int> > miners;
        multiset <int, greater <int> > diamonds;
        for (int i = 0; i < 2 * n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == 0) miners.insert(abs(y));
            else diamonds.insert(abs(x));
        }
        ld ans = 0;
        while (!miners.empty()) {
            ll a = *(miners.begin());
            ll b = *(diamonds.begin());
            miners.erase(miners.find(a));
            diamonds.erase(diamonds.find(b));
            ld dist = a * a + b * b;
            ans += sqrt(dist);
        }
        printf("%0.15Lf\n", ans);
    }
    return 0;
}