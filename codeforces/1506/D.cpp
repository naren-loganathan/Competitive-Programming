#include <iostream>
#include <vector>
#include <algorithm>
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
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        multiset <int, greater <int> > b;
        int removals = 0, cnt = 1;
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                b.insert(cnt);
                cnt = 1;
            } else {
                cnt += 1;
            }
        }
        b.insert(cnt);
        while (b.size() >= 2) {
            removals += 2;
            int one = *(b.begin());
            b.erase(b.find(one));
            int two = *(b.begin());
            b.erase(b.find(two));
            if (one > 1) {
                b.insert(one - 1);
            }
            if (two > 1) {
                b.insert(two - 1);
            }
        }
        cout << n - removals << '\n';
    }
    return 0;
}