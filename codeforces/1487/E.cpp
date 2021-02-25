#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector <int> n(4);
    for (int i = 0; i < 4; i++) {
        cin >> n[i];
    }
    vector < vector <int> > c(4), dp(4);
    for (int i = 0; i < 4; i++) {
        c[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> c[i][j];
        }
    }
    dp[0] = c[0];
    vector < vector < vector <int> > > b(3);
    for (int i = 0; i < 3; i++) {
        b[i].resize(n[i + 1]);
        int m; cin >> m;
        while (m--) {
            int x, y; cin >> x >> y;
            b[i][y - 1].push_back(x - 1);
        }
    }
    for (int i = 0; i < 3; i++) {
        dp[i + 1].resize(n[i + 1]);
        multiset <int> s;
        for (int j = 0; j < n[i]; j++) {
            s.insert(dp[i][j]);
        }
        for (int j = 0; j < n[i + 1]; j++) {
            for (auto k : b[i][j]) {
                s.erase(s.find(dp[i][k]));
            }
            if (s.empty()) {
                dp[i + 1][j] = 4e8 + 1;
            }
            else {
                dp[i + 1][j] = *s.begin() + c[i + 1][j];
            }
            for (auto k : b[i][j]) {
                s.insert(dp[i][k]);
            }
        }
    }
    int result = *min_element(dp[3].begin(), dp[3].end());
    if (result > 4e8) cout << "-1" << "\n";
    else cout << result << "\n";
    return 0;
}