#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector < vector <int> > v(26);
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < k; i++) {
        v[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        ll F = 0;
        string p; cin >> p;
        for (int j = 0; j < p.length(); j++) {
            int x = p[j] - 'a';
            if (v[x].empty()) {
                F += (ll) p.length();
            } else {
                ll idx = (ll) (lower_bound(v[x].begin(), v[x].end(), j) - v[x].begin());
                if (idx == v[x].size()) {
                    F += (ll) (abs(j - v[x].back()));
                } else {
                    ll add = v[x][idx] - j;
                    if (idx) {
                        add = min(add, (ll) j - v[x][idx - 1]);
                    }
                    F += add;
                }
            }
        }
        cout << F << '\n';
    }
    return 0;
}