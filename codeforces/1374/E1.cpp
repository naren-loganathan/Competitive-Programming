#include <iostream>
#include <vector>
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
    int n, k; cin >> n >> k;
    vector <int> books[4], cnt(4);
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        books[2 * a + b].push_back(t);
        cnt[2 * a + b] += 1;
    }
    int ans = -1;
    if (cnt[1] + cnt[3] >= k && cnt[2] + cnt[3] >= k)  {
        ans = 2e9;
        for (int i = 0; i < 4; i++) {
            sort(books[i].begin(), books[i].end());
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < books[i].size(); j++) {
                books[i][j] += books[i][j - 1];
            }
        }
        if (books[3].size() >= k) {
            ans = min(ans, books[3][k - 1]);
        }
        if (books[1].size() >= k && books[2].size() >= k) {
            ans = min(ans, books[1][k - 1] + books[2][k - 1]);
        }
        for (int i = 0; i < k - 1 && i < books[3].size(); i++) {
            if ((k - i - 1) <= books[1].size()) {
                if ((k - i - 1) <= books[2].size()) {
                    ans = min(ans, books[1][k - i - 2] + books[2][k - i - 2] + books[3][i]);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}