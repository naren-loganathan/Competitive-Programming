#include <iostream>
#include <vector>
#include <set>
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
    map <ll, ll> left, right;
    set <ll> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        left[l] += 1; right[r] += 1;
        s.insert(l); s.insert(r);
    }
    vector <ll> b;
    while (!s.empty()) {
        ll x = *(s.begin());
        b.push_back(x);
        s.erase(s.find(x));
    }
    int cover = left[b[0]] - right[b[0]];
    vector <ll> cnt(n + 1);
    cnt[left[b[0]]] += 1;
    for (int i = 1; i < b.size(); i++) {
        cnt[cover] += (b[i] - b[i - 1] - 1);
        cnt[cover + left[b[i]]] += 1;
        cover += left[b[i]] - right[b[i]];
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
    }
    cout << '\n';
    return 0;
}