#include <iostream>
#include <vector>
#include <string>
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
        string s, ans; cin >> s;
        int n = s.length();
        vector <int> cnt(26), vis(26, 1), idx;
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a'] += 1;
            vis[s[i] - 'a'] = 0;
        }
        idx.push_back(-1);
        for (int i = 0; i < 26; i++) {
            bool poss = 0;
            for (int j = 25; j >= 0; j--) {
                if (!vis[j]) {
                    for (int k = idx.back() + 1; k < n; k++) {
                        if (s[k] == 'a' + j) {
                            for (int l = idx.back() + 1; l < k; l++) {
                                cnt[s[l] - 'a'] -= 1;
                            }
                            bool can = 1;
                            for (int l = 0; l < 26; l++) {
                                if (!vis[l] && cnt[l] == 0) {
                                    can = 0; break;
                                }
                            }
                            if (can) {
                                idx.push_back(k);
                                vis[j] = 1; poss = 1;
                            } else {
                                for (int l = idx.back() + 1; l < k; l++) {
                                    cnt[s[l] - 'a'] += 1;
                                }
                            }
                            break;
                        }
                    }
                    if (poss) break;
                }
            }
        }
        for (int i = 1; i < idx.size(); i++) {
            if (idx[i] >= 0) ans += s[idx[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}