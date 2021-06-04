#include <iostream>
#include <vector>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int gcd (int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> a(n), even, odd;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }
        int ans = 0, cnt = n - 1;
        for (int i = 0; i < even.size(); i++) {
            ans += cnt;
            cnt--;
        }
        for (int i = 0; i < odd.size(); i++) {
            for (int j = i + 1; j < odd.size(); j++) {
                if (gcd(odd[i], odd[j]) > 1) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}