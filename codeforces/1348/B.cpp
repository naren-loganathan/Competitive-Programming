#include <iostream>
#include <vector>
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
        int n, k; cin >> n >> k;
        vector <int> a(n), v;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set <int> s;
        for (int i = 0; i < n; i++) {
            if (s.find(a[i]) == s.end()) {
                s.insert(a[i]);
                v.push_back(a[i]);
            }
        }
        while (v.size() < k) {
            v.push_back(1);
        }
        if (s.size() > k) {
            cout << -1 << '\n';
        } else {
            cout << 100 * v.size() << '\n';
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < k; j++) {
                    cout << v[j] << ' ';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}