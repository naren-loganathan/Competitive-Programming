#include <iostream>
#include <string>
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
        int n, m; cin >> n >> m;
        string s; cin >> s;
        int l = 0, r = n - 1;
        vector < pair <int, int> > v;
        while (l < n && s[l] == '0') l++;
        while (r >= 0 && s[r] == '0') r--;
        if (l != n) {
            int len = 0, st = -1;
            for (int i = l; i <= r; i++) {
                if (s[i] == '0') {
                    if (len == 0) {
                        st = i;
                    }
                    len++;
                } else {
                    if (len != 0) {
                        v.push_back(mp(st, len));
                        len = 0;
                    }
                }
            }
            for (int i = 0; i < v.size(); i++) {
                int ft = v[i].fi, rt = v[i].fi + v[i].se - 1, cnt = 0;
                while (ft < rt && cnt < m) {
                    s[ft] = '1';
                    s[rt] = '1';
                    ft++; rt--; cnt++;
                }
            }
            int cnt = 0, curr = l - 1;
            while (curr >= 0 && cnt < m) {
                s[curr] = '1';
                curr--; cnt++;
            }
            cnt = 0; curr = r + 1;
            while (curr < n && cnt < m) {
                s[curr] = '1';
                curr++; cnt++;
            }
        }
        cout << s << '\n';
    }
    return 0;
}
