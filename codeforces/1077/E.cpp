#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> v;
    map <int, int> cnt;
    vector <int> pow2(30, 1);
    for (int i = 1; i < 30; i++) {
        pow2[i] = 2 * pow2[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a]++;
    }
    map <int, int> :: iterator it;
    for (it = cnt.begin(); it != cnt.end(); it++) {
        v.push_back(it -> se);
    }
    sort(v.begin(), v.end());
    int m = (int) v.size();
    vector <int> dp(m), pr(m);
    dp[m - 1] = v[m - 1]; pr[m - 1] = v[m - 1];
    int c = 2;
    for (int i = m - 2; i >= 0; i--) {
        if (v[i] >= pr[i + 1] / 2) {
            pr[i] = pr[i + 1] / 2;
            dp[i] = pr[i] * (pow2[c++] - 1);
        } else {
            pr[i] = v[i];
            dp[i] = pr[i] * (pow2[c++] - 1);
        }
        if (pr[i] < 2) {
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}