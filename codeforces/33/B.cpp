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
    string s, t; cin >> s >> t;
    if (s.length() != t.length()) {
        cout << -1 << '\n';
        return 0;
    }
    vector < vector <int> > d(26, vector <int> (26, 1e9));
    for (int i = 0; i < 26; i++) {
        d[i][i] = 0;
    }
    int n; cin >> n;
    while (n--) {
        int w; char a, b;
        cin >> a >> b >> w;
        d[a - 'a'][b - 'a'] = min(d[a - 'a'][b - 'a'], w);
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    bool poss = 1; ll ans = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = 'a'; int cost = 2e9;
        for (int j = 0; j < 26; j++) {
            if (cost > d[s[i] - 'a'][j] + d[t[i] - 'a'][j]) {
                cost = d[s[i] - 'a'][j] + d[t[i] - 'a'][j];
                c = 'a' + j;
            }
        }
        if (cost >= 1e9) {
            poss = 0; break;
        } else {
            ans += (ll) cost;
            s[i] = c;
        }
    }
    if (poss) {
        cout << ans << '\n' << s << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}