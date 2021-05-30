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
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector < vector <int> > ans(n), idx(n + 1);
        ans[0].push_back(1);
        idx[1].push_back(0);
        vector <bool> complete(n);
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                ans[i] = ans[i - 1];
                ans[i].push_back(1);
            } else {
                while (complete[idx[a[i] - 1].back()]) {
                    idx[a[i] - 1].pop_back();
                }
                ans[i] = ans[idx[a[i] - 1].back()];
                ans[i].back()++;
                for (int j = idx[a[i] - 1].back(); j < i; j++) {
                    complete[j] = true;
                }
                idx[a[i] - 1].pop_back();
            }
            idx[a[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (j + 1 != ans[i].size()) {
                    cout << ans[i][j] << '.';
                } else {
                    cout << ans[i][j] << '\n';
                }
            }
        }
    }
    return 0;
}