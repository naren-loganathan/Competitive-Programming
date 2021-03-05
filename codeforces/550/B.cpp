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
    int n, l, r, x, ans = 0; 
    cin >> n >> l >> r >> x;
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    for (int i = 3; i < (1 << n); i++) {
        int tot = 0, problems = 0;
        vector <int> scores;
        for (int j = 15; j >= 0; j--) {
            if (i & (1 << j)) {
                scores.push_back(c[j]), tot += c[j];
            }
        }
        if (scores.front() - scores.back() >= x) {
            if (tot >= l && tot <= r) {
                ans += 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}