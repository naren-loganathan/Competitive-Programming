#include <iostream>
#include <set>
using namespace std;
     
typedef long long int ll;
#define fi first
#define se second
#define mp make_pair
#define N 100005
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, b; cin >> n;
        set <int> numbers;
        for (int i = 0; i < n; i++) {
            cin >> b;
            numbers.insert(b);
        }
        cout << (numbers.size() < n ? "YES" : "NO") << "\n";
    }
    return 0;
}