#include <iostream>
#include <vector>
#include <map>
#include <set>
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
        int n, m; cin >> n >> m;
        int lim = m / 2 + (m % 2);
        vector <int> cnt(n + 1), ans(m);
        set <int> day[m];
        for (int i = 0; i < m; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int f; cin >> f;
                if (j == 0) {
                    ans[i] = f; cnt[f] += 1;
                } else {
                    day[i].insert(f);
                }
            }
        }
        bool poss = 1;
        int problem = 0;;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > lim) {
                problem = i;
                break;
            }
        }
        if (problem) {
            for (int i = 0; i < m; i++) {
                if (ans[i] == problem) {
                    if (!day[i].empty()) {
                        int new_f = *(day[i].begin());
                        day[i].erase(day[i].find(new_f));
                        ans[i] = new_f;
                        cnt[problem] -= 1;
                        cnt[new_f] += 1;
                        if (cnt[problem] == lim) {
                            break;
                        }
                    }
                }
            }
        }
        if (cnt[problem] > lim) {
            poss = 0;
        } else {
            problem = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] > lim) {
                    problem = i;
                    break;
                }
            }
            if (problem) {
                for (int i = 0; i < m; i++) {
                    if (ans[i] == problem) {
                        if (!day[i].empty()) {
                            int new_f = *(day[i].begin());
                            day[i].erase(day[i].find(new_f));
                            ans[i] = new_f;
                            cnt[problem] -= 1;
                            cnt[new_f] += 1;
                            if (cnt[problem] == lim) {
                                break;
                            }
                        }
                    }
                }
            }
            if (cnt[problem] > lim) {
                poss = 0;
            }
        }
        if (poss) {
            cout << "YES" << '\n';
            for (int i = 0; i < m; i++) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}