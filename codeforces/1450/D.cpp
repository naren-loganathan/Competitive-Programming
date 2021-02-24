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
        int n; cin >> n;
        vector <int> a(n + 1, 1e9), cnt(n + 1, 0);
        string s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; cnt[a[i]]++;
            s += '0';
        }
        if (cnt[1]) {
            s[0] = '1'; s[n - 1] = '1';
            for (int i = 1; i <= n; i++) {
                if (!cnt[i]) s[0] = '0';
            }
            if (n > 2) {
                int l = 1, r = n, i = 1;
                while (l < r - 1 && cnt[i] == 1) {
                    if (cnt[i + 1]) {
                        if (a[l] == i || a[r] == i) {
                            if (a[l] == i) l++;
                            else r--;
                            i++;
                        }
                        else break;
                    }
                    else break;
                }
                i -= 1;
                for (int j = n - i - 1; j < n - 1; j++) {
                    s[j] = '1';
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}