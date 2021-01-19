#include <iostream>
#include <vector>
#include <queue>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, colour; cin >> n;
    vector <int> p(n), a(n), b(n);
    vector <bool> bought(n, 0);
    vector < priority_queue < pair <int, int> > > c(3);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i] - 1].push(mp(-p[i], i));
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[b[i] - 1].push(mp(-p[i], i));
    }
    int m; cin >> m;
    vector <int> res(m);
    for (int i = 0; i < m; i++) {
        cin >> colour;
        colour--;
        if (c[colour].empty()) {
            res[i] = -1;
        }
        else {
            while (!c[colour].empty() && bought[c[colour].top().se]) {
                c[colour].pop();
            }
            if (c[colour].empty()) {
                res[i] = -1;
            }
            else {
                res[i] = (-1) * c[colour].top().fi;
                bought[c[colour].top().se] = 1;
                c[colour].pop();
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}
