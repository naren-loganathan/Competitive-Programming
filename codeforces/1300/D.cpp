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
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    if (n % 2) {
        cout << "NO" << '\n';
    } else {
        set < pair <int, int> > s;
        for (int i = 0; i < n; i++) {
            s.insert(mp(x[i] + x[(i + n / 2) % n], y[i] + y[(i + n / 2) % n]));
        }
        cout << (s.size() == 1 ? "YES" : "NO") << '\n';
    }
    return 0;
}