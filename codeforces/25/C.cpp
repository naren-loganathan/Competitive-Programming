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
    ll n; cin >> n;
    vector < vector <ll> > d(n, vector <ll> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    ll k; cin >> k;
    while (k--) {
        ll a, b, c, q = 0;
        cin >> a >> b >> c;
        a--; b--;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], min(d[i][a] + d[b][j] + c, d[i][b] + d[a][j] + c));
                q += d[i][j];
            }
        }
        cout << q / 2 << ' ';
    }
    cout << '\n';
    return 0;
}