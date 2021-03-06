#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset <int, greater <int> > left;
    multiset <int> right;
    int n; cin >> n;
    vector < pair <int, int> > segs(n);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        segs[i] = mp(l, r);
        left.insert(l); right.insert(r);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        left.erase(left.find(segs[i].fi));
        right.erase(right.find(segs[i].se));
        ans = max(ans, *right.begin() - *left.begin());
        left.insert(segs[i].fi);
        right.insert(segs[i].se);
    }
    cout << ans << '\n';
    return 0;
}