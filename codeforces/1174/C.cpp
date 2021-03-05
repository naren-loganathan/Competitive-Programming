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
    int n, cnt = 2; cin >> n;
    vector <int> a(n + 1, 1);
    for (int i = 3; i <= n; i += 2) {
        if (a[i] == 1) {
            for (int j = i; j <= n; j += 2 * i) {
                a[j] = cnt;
            }
            cnt += 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}