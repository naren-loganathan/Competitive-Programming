#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    vector <string> p;
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.' || (s[i] > 47 && s[i] < 58)) {
            string price = "";
            while (i < s.length() && (s[i] == '.' || (s[i] > 47 && s[i] < 58))) {
                price += s[i]; i += 1;
            }
            int j = price.length() - 1;
            while (j >= 0 && price[j] != '.') {
                j -= 1;
            }
            if (j <= 0 || j != price.length() - 3) {
                price += ".00";
            }
            reverse(price.begin(), price.end());
            p.push_back(price);
            int digits = price.length();
            len = max(len, digits);
        }
    }
    int carry = 0;
    string ans = "";
    for (int i = 0; i < len; i++) {
        bool decimal = 0;
        for (int j = 0; j < p.size(); j++) {
            if (p[j].length() > i && p[j][i] == '.') {
                decimal = 1; break;
            }
            if (p[j].length() > i && p[j][i] != '.') {
                carry += (p[j][i] - 48);
            }
        }
        if (decimal) ans += '.';
        else {
            char c = 48 + (carry % 10);
            ans += c;
            carry /= 10;
        }
    }
    while (carry) {
        char c = (carry % 10) + 48;
        ans += c;
        carry /= 10;
    }
    string res = "";
    if (ans[0] != '0' || ans[1] != '0') {
        res += ans.substr(0, 3);
    }
    int cnt = 0;
    for (int i = 3; i < ans.length(); i++) {
        if (cnt == 3) {
            res += '.'; cnt = 0;
        }
        if (ans[i] != '.') {
            res += ans[i]; cnt += 1;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
    return 0;
}