#include <iostream>
#include <set>
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
    int t; cin >> t;
    multiset <ll> m;
    while (t--) {
        ll n, sum = 0; 
        cin >> n;
        vector <ll> b(n + 2);
        m.clear();
        for (int i = 0; i < n + 2; i++) {
            ll num; cin >> num;
            b[i] = num;
            sum += num;
            m.insert(num);
        }
        bool done = 0;
        for (int i = 0; i < n + 2; i++) {
            ll rem = sum - b[i];
            if (rem % 2 == 0) {
                ll s = rem / 2;
                m.erase(m.find(b[i]));
                if (m.find(s) != m.end()) {
                    m.erase(m.find(s));
                    while (!m.empty()) {
                        ll val = *(m.begin());
                        cout << val << ' ';
                        m.erase(m.find(val));
                    }
                    cout << '\n';
                    done = 1;
                    break;
                } else {
                    m.insert(b[i]);
                }
            }
        }
        if (!done) {
            cout << -1 << '\n';
        }
    }
    return 0;
}