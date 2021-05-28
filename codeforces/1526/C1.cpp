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
    int n; cin >> n;
    vector <ll> a(n), take(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set < pair <ll, ll> > neg_set;
    ll curr = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            curr += a[i];
            take[i] = 1;
        } else {
            if (curr + a[i] < 0) {
                if (!neg_set.empty()) {
                    pair <ll, ll> rem = *(neg_set.begin());
                    if (curr - rem.fi + a[i] >= 0 && rem.fi < a[i]) {
                        take[rem.se] = 0; take[i] = 1;
                        curr = curr - rem.fi + a[i];
                        neg_set.erase(rem);
                        neg_set.insert(mp(a[i], i));
                    }
                }
            } else {
                neg_set.insert(mp(a[i], i));
                curr += a[i];
                take[i] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (take[i] == 1) {
            cnt += 1;
        }
    }
    cout << cnt << '\n';
    return 0;
}