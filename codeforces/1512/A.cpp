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
        int n; cin >> n;
        vector < vector <int> > cnt(101);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a].push_back(i + 1);
        }
        for (int i = 1; i <= 100; i++) {
            if (cnt[i].size() == 1) {
                cout << cnt[i][0] << '\n';
                break;
            }
        }
    }
    return 0;
}