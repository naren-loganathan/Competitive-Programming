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
    int n, size; cin >> n;
    vector <int> s;
    for (int i = 0; i < n; i++) {
        cin >> size;
        s.push_back(size);
    }
    int cnt = n, big = n - 1, small = n / 2 - 1;
    sort(s.begin(), s.end());
    while (small >= 0 && big >= n / 2) {
        while (s[small] * 2 > s[big] && small >= 0) {
            small--;
        }
        if (small >= 0) {
            cnt--; big--; small--;
        }
    }
    cout << cnt << "\n";
    return 0;
}