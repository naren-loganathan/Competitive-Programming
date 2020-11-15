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
    int t; cin >> t;
    while (t--) {
        ll n, W, lb; cin >> n >> W;
        (W % 2 ? lb = W / 2 + 1 : lb = W / 2);
        vector < pair <ll, ll> > w(n + 1);
        w[0].fi = 0, w[0].se = 0;
        for (int i = 1; i <= n; i++) {
            cin >> w[i].fi;
            w[i].se = i;
        }
        sort(w.begin(), w.end());
        for (int i = 1; i <= n; i++) {
            w[i].fi += w[i - 1].fi;
        }
        bool possible = 1;
        int l = 0, r = 1;
        while (w[r].fi - w[l].fi < lb || w[r].fi - w[l].fi > W) {
            if (w[r].fi - w[l].fi < lb) {
                r++;
            }
            else if (w[r].fi - w[l].fi > W) {
                l++;
            }
            if (r == n + 1 || l >= r) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            vector <int> ans;
            for (int i = l + 1; i <= r; i++) {
                ans.push_back(w[i].se);
            }
            sort(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}