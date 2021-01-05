#include <iostream>
#include <vector>
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
        int n, x, num; cin >> n >> x;
        ll sum = 0;
        vector < pair <ll, ll> > a;
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.push_back(mp(num, 1));
        }
        int i = 0;
        while (a[i].fi % x == 0) {
            a.push_back(mp(a[i].fi / x, a[i].se * x));
            i++;
        }
        for (int i = 0; i < a.size(); i++) {
            sum += a[i].fi * a[i].se; 
        }
        cout << sum << "\n";
    }
    return 0;
}