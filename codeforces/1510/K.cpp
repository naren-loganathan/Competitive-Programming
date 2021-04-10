#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> p(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> p[i];
    }
    int ans = 2 * n + 1;
    for (int m = 0; m < 2; m++) {
        int k = 0;
        vector <int> v = p;
        for (int i = 0; i <= 2 * n; i++) {
            if (!is_sorted(v.begin(), v.end())) {
                if ((k + m) % 2) {
                    for (int j = 0; j < 2 * n; j += 2) {
                        swap(v[j], v[j + 1]);
                    }
                } else {
                    for (int j = 0; j < n; j++) {
                        swap(v[j], v[j + n]);
                    }
                }
                k += 1;
            } else {
                break;
            }
        }
        ans = min(ans, k);
    }
    cout << (ans <= 2 * n ? ans : -1) << '\n';
    return 0;
}