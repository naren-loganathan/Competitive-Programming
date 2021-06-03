#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;   

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector <int> a(n), ans(n);
    int curr_used = 0;
    vector < pair <int, int> > c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans[i] = (a[i] + 1) / 2;
        curr_used += ans[i];
        c[i] = mp(-a[i], i);
    }
    sort(c.begin(), c.end());
    if (curr_used > w) {
        cout << -1 << '\n';
    } else {
        int i = 0;
        while (curr_used < w) {
            int add = min(-c[i].fi / 2, w - curr_used);
            ans[c[i].se] += add;
            curr_used += add;
            i++;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
