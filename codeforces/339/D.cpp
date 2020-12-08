#include <iostream>
#include <vector>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < pair <ll, ll> > tree(1 << 18);    //.se = 0 -> OR, .se = 1 -> XOR

ll parent (ll i) {
    return (i / 2);
}

ll left (ll i) {
    return (2 * i);
}

ll right (ll i) {
    return (2 * i + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, p, b; 
    cin >> n >> m;
    vector <ll> a(1 << n);
    for (ll i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    for (ll i = (1 << n); i < (1 << (n + 1)); i++) {
        tree[i] = mp(a[i - (1 << n)], 0);
    }
    for (ll i = (1 << n) - 1; i > 0; i--) {
        ll val = 0, op = 0;
        if (tree[left(i)].se) {
            val = tree[left(i)].fi ^ tree[right(i)].fi;
        }
        else {
            val = tree[left(i)].fi | tree[right(i)].fi;
            op = 1;
        }
        tree[i] = mp(val, op);
    }
    while (m--) {
        cin >> p >> b;
        tree[(1 << n) + p - 1] = mp(b, 0);
        ll idx = parent((1 << n) + p - 1);
        while (idx > 0) {
            ll val = 0, op = 0;
            if (tree[left(idx)].se) {
                val = tree[left(idx)].fi ^ tree[right(idx)].fi;
            }
            else {
                val = tree[left(idx)].fi | tree[right(idx)].fi;
                op = 1;
            }
            tree[idx] = mp(val, op);
            idx = parent(idx);
        }
        cout << tree[1].fi << "\n";
    }
    return 0;
}