#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, w = 1; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector <int> curr(m);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j >= m) break;
        else {
            if (s[i] == t[j]) {
                curr[j] = i;
                if (j) w = max(w, curr[j] - curr[j - 1]);
                j++;
            }
        }
    }
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (j == 0) break;
        else {
            if (s[i] == t[j]) {
                w = max(w, i - curr[j - 1]);
                j--;
            }
        }
    }
    cout << w << "\n";
    return 0;
}