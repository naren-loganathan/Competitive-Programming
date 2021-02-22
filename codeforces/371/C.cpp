#include <iostream>
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
    string s; cin >> s;
    ll d[3][3];
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            d[0][j] = 0; cin >> d[i][j];
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') d[0][0]++;
        else if (s[i] == 'S') d[0][1]++;
        else d[0][2]++;
    }
    ll r, lo = 0, hi = 1e13, mid, cost; 
    cin >> r;
    while (lo < hi) {
        mid = (lo + hi) >> 1; cost = 0;
        ll c = mid + (lo == mid);
        for (int i = 0; i < 3; i++) {
            cost += max(0LL, (d[0][i] * c - d[1][i]) * d[2][i]);
        }
        if (cost > r) {
            (lo == mid ? hi-- : hi = mid - 1);
        }
        else {
            (lo == mid ? lo++ : lo = mid);
        }
    }
    cout << lo << "\n";
    return 0;
}