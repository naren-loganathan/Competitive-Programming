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
    int t; cin >> t;
    while (t--) {
        int n, m, pos; cin >> n >> m;
        vector <int> a[2], b[2];
        for (int i = 0; i < n; i += 1) {
            cin >> pos;
            if (pos < 0) a[1].push_back(-pos);
            else a[0].push_back(pos);
        }
        for (int i = 0; i < m; i += 1) {
            cin >> pos;
            if (pos < 0) b[1].push_back(-pos);
            else b[0].push_back(pos);
        }
        reverse(a[1].begin(), a[1].end());
        reverse(b[1].begin(), b[1].end());
        int result = 0;
        for (int i = 0; i < 2; i += 1) {
            int x = a[i].size(), y = b[i].size();
            set <int> s(b[i].begin(), b[i].end());
            vector <int> suffix(x + 1, 0);
            for (int j = x - 1; j >= 0; j -= 1) {
                suffix[j] = suffix[j + 1] + (s.count(a[i][j]));
            }
            int cnt = suffix[0], r = 0, j = 0;
            for (int l = 0; l < y; l += 1) {
                while (j < x and a[i][j] <= b[i][l] + j) j += 1;
                while (r < y and b[i][r] - b[i][l] < j) r += 1;
                cnt = max(cnt, r - l + suffix[j]);
            }
            result += cnt;
        }
        cout << result << "\n";
    }
    return 0;
}