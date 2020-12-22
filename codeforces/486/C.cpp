#include <iostream>
#include <string>
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
    int n, p, cnt = 0; 
    cin >> n >> p; p--;
    string s; cin >> s;
    vector <int> diff(n, 0);
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            diff[i] = min((s[i] - s[n - 1 - i] + 26) % 26, (s[n - 1 - i] - s[i] + 26) % 26);
            diff[n - 1 - i] = diff[i];
        }
    }
    int sl = -1, el = -1, sr = -1, er = -1, inc = 0;
    for (int i = 0; i < n / 2; i++) {
        if (diff[i]) {
            if (sl == -1) {
                sl = i;
            }
            el = i;
            inc += diff[i];
        }
    }
    if (sl + el != -2) {
        sr = n - 1 - sl;
        er = n - 1 - el;
        cnt += inc + (el - sl);
        cnt += min(abs(p - sl), min(abs(p - el), min(abs(p - sr), abs(p - er))));
    }
    cout << cnt << "\n";
    return 0;
}