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
        int n; cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector <int> cur;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cur.push_back(1);
            } else {
                while (cur.back() != a[i] - 1) {
                    cur.pop_back();
                }
                cur.back()++;
            }
            for (int j = 0; j < cur.size() - 1; j++) {
                cout << cur[j] << '.';
            }
            cout << cur.back() << '\n';
        }
    }
    return 0;
}