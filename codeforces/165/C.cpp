#include <iostream>
#include <string>
#include <map>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k, length = 0, cnt1 = 0; cin >> k;
    string s; cin >> s;
    map <ll, ll> prefix_sums;
    prefix_sums[0]++;
    ll result_0 = 0, result_1 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            cnt1++;
            if (length) {
                result_0 += (length) * (length + 1) / 2;
                length = 0;
            }
        }
        else {
            length++;
        }
        prefix_sums[cnt1]++;
    }
    if (length) {
        result_0 += (length) * (length + 1) / 2;
    }
    for (auto it : prefix_sums) {
        result_1 += it.se * prefix_sums[it.fi - k];
    }
    cout << (k ? result_1 : result_0) << "\n";
    return 0;
}
