#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
        int n; cin >> n;
        int result = n - 1;
        vector <int> l(n), r(n);
        map <int, pair <int, int> > m;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            m[i + 1] = mp(l[i], r[i]);
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        for (int i = 1; i <= n; i++) {
            pair <int, int> seg = m[i];
            int left = lower_bound(r.begin(), r.end(), m[i].fi) - r.begin();
            int right = n - (lower_bound(l.begin(), l.end(), m[i].se + 1) - l.begin());
            result = min(result, left + right);
        }
        cout << result << "\n";
    }
    return 0;
}
