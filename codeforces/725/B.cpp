#include <iostream>
#include <string>
#include <cmath>
using namespace std;   

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int extra[] = {4, 5, 6, 3, 2, 1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, n = ""; 
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            n += s[i];
        } else {
            break;
        }
    }
    ll num = stoll(n), ans = 0;
    if (num % 4) {
        ans += 12 * (num / 4) + (num / 4) * 4;
    } else {
        ans += 12 * ((num - 1) / 4) + ((num - 1) / 4) * 4;
    }
    ll x = num % 4;
    if (x == 0 || x == 2) {
        ans += 7;
    }
    cout << ans + extra[s.back() - 'a'] << '\n';
    return 0;
}
