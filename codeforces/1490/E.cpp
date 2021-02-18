#include <iostream>
#include <vector>
#include <set>
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
        vector <ll> a(n), b(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        set <ll> s;
        for (int i = 0; i < n; i++) {
            p[i] = b[i] + (i ? p[i - 1] : 0);
        }
        int block = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (p[i] < b[i + 1]) {
                block = i;
                break;
            }
        }
        for (int i = block + 1; i < n; i++) {
            s.insert(b[i]);
        }
        vector <int> ans;
        for (int i = 0; i < n; i++) {
            if (s.find(a[i]) != s.end()) {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}