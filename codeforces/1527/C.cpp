#include <iostream>
#include <vector>
#include <map>
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
        int n; cin >> n;
        ll ans = 0;
        map <int, vector <int> > m;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            m[a].push_back(i);
        }
        map <int, vector <int> > :: iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            vector <int> v = it -> se;
            if (v.size() > 1) {
                vector <ll> r(v.size());
                for (int i = v.size() - 1; i >= 0; i--) {
                    r[i] = n - v[i];
                    if (i + 1 < v.size()) {
                        r[i] += r[i + 1];
                    }
                }
                for (int i = 0; i + 1 < v.size(); i++) {
                    ans += ((ll) (v[i] + 1)) * (r[i + 1]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}