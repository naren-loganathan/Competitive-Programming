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
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    int n, t; cin >> n;
    vector <int> neg(n, 0), pos(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t <= 0) {
            pos[i] = 1;
        }
        if (t >= 0) {
            neg[i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        neg[i] += neg[i - 1];
        pos[n - 1 - i] += pos[n - i];
    }
    int cnt = n;
    for (int i = 0; i < n - 1; i++) {
        cnt = min(cnt, neg[i] + pos[i + 1]);
    }
    cout << cnt << "\n";
    return 0;
}