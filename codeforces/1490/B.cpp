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
        int n, a; cin >> n;
        vector <int> rem(3);
        for (int i = 0; i < n; i++) {
            cin >> a;
            rem[a % 3]++;
        }
        int idx = 0, cnt = 0;
        while (idx <= 6) {
            if (rem[(idx % 3)] > n / 3) {
                cnt += rem[(idx % 3)] - (n / 3);
                rem[(idx + 1) % 3] += rem[(idx % 3)] - (n / 3);
                rem[(idx % 3)] = n / 3;
            }
            idx++;
        }
        cout << cnt << "\n";
    }
    return 0;
}