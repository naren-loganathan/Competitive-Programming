#include <iostream>
#include <vector>
#include <string>
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
        int n, m; cin >> n >> m;
        vector <string> a(n);
        for (int i = 0; i < n; i += 1) {
            cin >> a[i];
        }
        string answer = a[0];
        if (n == 1) cout << answer << '\n';
        else {
            bool possible = 0;
            for (int i = 0; i < m and !possible; i += 1) {
                answer = a[0];
                for (int j = 97; j < 123 and !possible; j += 1) {
                    answer[i] = j; 
                    bool check = 1;
                    for (int k = 1; k < n; k += 1) {
                        int cnt = 0;
                        for (int l = 0; l < m; l += 1) {
                            if (answer[l] != a[k][l]) cnt += 1;
                        }
                        if (cnt > 1) check = 0;
                    }
                    possible |= check;
                }
            }
            if (!possible) cout << -1 << '\n';
            else cout << answer << '\n';
        }
    }
    return 0;
}