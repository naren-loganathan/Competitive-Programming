#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
        int n, k, result = 0; cin >> n;
        vector <int> a(n), adj;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            if (i) {
                if (a[i] == -1 && a[i - 1] != -1) {
                    adj.push_back(a[i - 1]);
                }
            }
            if (i < n - 1) {
                if (a[i] == -1 && a[i + 1] != -1) {
                    adj.push_back(a[i + 1]);
                }
            }
        }
        if (!adj.empty()) {
            sort(adj.begin(), adj.end());
            k = (adj.front() + adj.back()) / 2;
        }
        else {
            k = 0;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = k;
            }
            if (i) {
                result = max(result, abs(a[i] - a[i - 1]));
            }
        }
        cout << result << " " << k << "\n";
    }
    return 0;
}
