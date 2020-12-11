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
        int n, m, r;
        double p, failure = 1.0; 
        cin >> n >> m;
        vector <int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int mx = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] != i) {
                mx = i;
                break;
            }
        }
        while (m--) {
            cin >> r >> p;
            if (mx == 0) {
                failure = 0.0;
            }
            else if (r >= mx) {
                failure *= (1.0 - p);
            }
        }
        printf("%0.6lf\n", (1.0 - failure));
    }
    return 0;
}