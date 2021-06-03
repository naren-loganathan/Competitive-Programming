#include <iostream>
#include <vector>
#include <cmath>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n, m; cin >> n >> m;
    vector <int> a(n), b(m);
    ll bus_sum = 0, trolley_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bus_sum += min(c2, c1 * a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        trolley_sum += min(c2, c1 * b[i]);
    }
    bus_sum = min(bus_sum, c3);
    trolley_sum = min(trolley_sum, c3);
    cout << min(c4, bus_sum + trolley_sum) << '\n';
    return 0;
}