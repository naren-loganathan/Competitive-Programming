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
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += 420690;
    }
    cout << n + 1 << "\n" << "1" << " " << n << " " << 420690 << "\n";
    for (int i = 0; i < n; i++) {
        cout << "2" << " " << i + 1 << " " << a[i] - i - 1 << "\n";
    }
    return 0;
}