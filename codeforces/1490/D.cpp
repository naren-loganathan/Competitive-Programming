#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

map <int, int> d;
vector <int> a(100);

void construct (int l, int r, int depth) {
    if (l > r) return;
    int idx = 0, val = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] > val) {
            idx = i;
            val = a[i];
        }
    }
    d[idx] = depth;
    construct(l, idx - 1, depth + 1);
    construct(idx + 1, r, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        construct(0, n - 1, 0);
        for (int i = 0; i < n; i++) {
            cout << d[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}