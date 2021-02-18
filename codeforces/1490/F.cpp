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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n);
        map <int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i]; m[a[i]]++;
        }
        vector <int> qts;
        for (auto it : m) {
            qts.push_back(it.se);
        }
        int sz = qts.size();
        sort(qts.begin(), qts.end());
        vector <int> p(sz);
        for (int i = 0; i < sz; i++) {
            p[i] = qts[i] + (i ? p[i - 1] : 0);
        }
        int remove = n;
        for (int i = 0; i < sz; i++) {
            remove = min(remove, p.back() - (sz - i) * qts[i]);
        }
        cout << remove << "\n";
    }
    return 0;
}