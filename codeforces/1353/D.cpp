#include <iostream>
#include <vector>
#include <set>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector <int> a(2e5 + 1);

void construct (int n) {
    int mid = (n + 1) >> 1, cnt = 1;
    a[mid] = cnt; cnt++;
    set < pair <int, int> , greater < pair <int, int> > > s;
    if (mid > 1) {
        s.insert(mp(mid - 1, -1));
    }
    if (n > mid) {
        s.insert(mp(n - mid, -(mid + 1)));
    }
    while (!s.empty()) {
        pair <int, int> seg = *s.begin();
        s.erase(seg);
        int l = -seg.se, r = seg.fi - seg.se - 1;
        mid = (l + r) >> 1;
        a[mid] = cnt; cnt++;
        if (mid > l) {
        s.insert(mp(mid - l, -l));
        }
        if (r > mid) {
            s.insert(mp(r - mid, -(mid + 1)));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        construct(n);
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}