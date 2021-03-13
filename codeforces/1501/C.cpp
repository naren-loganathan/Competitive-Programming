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
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector < vector < pair <int, int> > > duo(5e6 + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (!duo[sum].empty()) {
                if (duo[sum].size() < 3) {
                    for (int k = 0; k < duo[sum].size(); k++) {
                        pair <int, int> p = duo[sum][k];
                        if (p.fi != i + 1 && p.fi != j + 1 && p.se != i + 1 && p.se != j + 1) {
                            cout << "YES" << '\n';
                            cout << i + 1 << ' ' << j + 1 << ' ' << p.fi << ' ' << p.se << '\n';
                            return 0;
                        }
                    }
                    duo[sum].push_back(mp(i + 1, j + 1));
                } else {
                    cout << "YES" << '\n';
                    duo[sum].push_back(mp(i + 1, j + 1));
                    bool bleh = 1;
                    for (int i = 1; i < 4; i++) {
                        if (duo[sum][i].fi != duo[sum][i - 1].fi) bleh = 0; 
                    }
                    if (bleh) {
                        for (int i = 0; i < 4; i++) {
                            cout << duo[sum][i].se << ' ';
                        }
                        cout << '\n';
                        return 0;
                    } else {
                        for (int i = 0; i < 4; i++) {
                            for (int j = i + 1; j < 4; j++) {
                                pair <int, int> u = duo[sum][i], v = duo[sum][j];
                                if (v.fi != u.fi && v.fi != u.se && v.se != u.fi && v.se != u.se) {
                                    cout << v.fi << ' ' << v.se << ' ' << u.fi << ' ' << u.se << '\n';
                                    return 0;
                                }
                            }
                        }
                    }
                }
            } else {
                duo[sum].push_back(mp(i + 1, j + 1));
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}