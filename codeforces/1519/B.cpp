 #include <iostream>
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
        bool poss = 1;
        int n, m, k;
        cin >> n >> m >> k;
        if ((m - 1) + (m * (n - 1)) != k) {
            poss = 0;
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}