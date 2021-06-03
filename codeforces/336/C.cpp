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
    int cur = 1 << 29;
    vector <int> b;
    bool sol = false;
    while (!sol && cur) {
        for (int i = 0; i < n; i++) {
            if (a[i] & cur) {
                b.push_back(a[i]);
            }
        }
        if (!b.empty()) {
            int chk = b.front();
            for (int i = 1; i < b.size(); i++) {
                chk = (chk & b[i]);
            }
            if (chk % cur == 0) {
                sol = true;
            }
        }
        if (!sol) {
            cur /= 2; b.clear();
        }
    }
    if (sol) {
        cout << b.size() << '\n';
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}