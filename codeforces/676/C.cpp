#include <iostream>
#include <string>
#include <vector>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, max_beauty = 0; cin >> n >> k;
    string s; cin >> s;
    int l = 0, r = 0, cnt_a = 0, cnt_b = 0, swaps = 0;
    for (; l < n; l++) {
        if (l) {
            (s[l - 1] == 'a' ? cnt_a-- : cnt_b--);
        }
        swaps = min(cnt_a, cnt_b);
        while (swaps <= k && r < n) {
            if (s[r] == 'a') {
                cnt_a++;
            }
            else {
                cnt_b++;
            }
            swaps = min(cnt_a, cnt_b);
            if (swaps <= k) {
                r++;
            }
        }
        if (r < n) {
            (s[r] == 'a' ? cnt_a-- : cnt_b--);
        }
        max_beauty = max(max_beauty, r - l);
    }
    cout << max_beauty << "\n";
    return 0;
}
