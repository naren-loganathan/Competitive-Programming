#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

set <ll> slices;
vector <ll> a;

void build_slices (int l, int r) {
    ll sum = 0, mid = (a[l] + a[r]) / 2, idx = l;
    for (int i = l; i <= r; i++) {
        if (a[i] <= mid) {
            idx = i;
        }
        sum += a[i];
    }
    slices.insert(sum);
    if (idx - l > 0 && idx != r) {
        build_slices(l, idx);
    }
    else if (idx == l) {
        slices.insert(a[l]);
    }
    if (r - idx > 1) {
        build_slices(idx + 1, r);
    }
    else if (r - idx == 1) {
        slices.insert(a[r]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, q, num; cin >> n >> q;
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.push_back(num);
        }
        sort(a.begin(), a.end());
        build_slices(0, n - 1);
        while (q--) {
            ll s; cin >> s;
            cout << (slices.find(s) != slices.end() ? "Yes" : "No") << "\n";
        }
        slices.clear();
        a.clear();
    }
    return 0;
}
