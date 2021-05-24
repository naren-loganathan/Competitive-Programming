#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int prefix_function(string s) {
    vector <int> p(s.length());
    for (int i = 1; i < s.length(); i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p.back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    string ans = words[0];
    for (int i = 1; i < n; i++) {
        int x = ans.length(), y = words[i].length();
        string curr;
        if (x > y) {
            curr = words[i] + '|' + ans.substr(x - y, y);
        } else {
            curr = words[i].substr(0, x) + '|' + ans;
        }
        int rem = min(prefix_function(curr), min(x, y));
        if (rem != y) {
            ans += words[i].substr(rem, y - rem);
        }
    }
    cout << ans << '\n';
    return 0;
}