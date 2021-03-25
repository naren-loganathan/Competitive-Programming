#include <iostream>
#include <string>
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
        int n; cin >> n;
        string a[2]; cin >> a[0] >> a[1];
        vector <int> c[2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (i > 0 && a[j][i] != a[j][i - 1]) {
                    if (c[j].empty() || c[j].back() != i - 1) {
                        c[j].push_back(i - 1);
                    }
                }
                if (i == n - 1) {
                    if (a[j][i] == '1') {
                        c[j].push_back(i);
                    }
                }
            }
        }
        cout << c[0].size() + c[1].size() << ' ';
        for (int i = 0; i < c[0].size(); i++) {
            cout << c[0][i] + 1 << ' ';
        }
        for (int i = c[1].size() - 1; i >= 0; i--) {
            cout << c[1][i] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}