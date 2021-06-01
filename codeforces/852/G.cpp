#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    map <string, int> cnt;
    while (n--) {
        string s; cin >> s;
        cnt[s]++;
    }
    while (m--) {
        map <string, int> vis;
        int ans = 0;
        string t; cin >> t;
        vector <int> q;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '?') {
                q.push_back(i);
            }
        }
        if (q.size() == 0) {
            ans += cnt[t];
        } else {
            char c[] = {'a', 'b', 'c', 'd', 'e', 'f'};
            if (q.size() == 1) {
                for (int i = 0; i < 6; i++) {
                    t[q[0]] = c[i];
                    string new_t = "";
                    for (int i = 0; i < t.length(); i++) {
                        if (t[i] != 'f') {
                            new_t += t[i];
                        }
                    }
                    ans += cnt[new_t];
                }
            } else if (q.size() == 2) {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        t[q[0]] = c[i]; t[q[1]] = c[j];
                        string new_t = "";
                        for (int i = 0; i < t.length(); i++) {
                            if (t[i] != 'f') {
                                new_t += t[i];
                            }
                        }
                        if (vis[new_t] == 0) {
                            ans += cnt[new_t];
                            vis[new_t]++;
                        }
                    }
                }
            } else {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        for (int k = 0; k < 6; k++) {
                            t[q[0]] = c[i]; 
                            t[q[1]] = c[j];
                            t[q[2]] = c[k];
                            string new_t = "";
                            for (int i = 0; i < t.length(); i++) {
                                if (t[i] != 'f') {
                                    new_t += t[i];
                                }
                            }
                            if (vis[new_t] == 0) {
                                ans += cnt[new_t];
                                vis[new_t]++;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}