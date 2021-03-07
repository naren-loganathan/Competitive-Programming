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
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if (n % k) cout << -1 << '\n';
        else {
            vector <int> cnt(26, 0);
            for (int i = 0; i < n; i++) {
                cnt[s[i] - 'a']++;
            }
            bool beautiful = 1;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % k) beautiful = 0;
            }
            if (beautiful) cout << s << '\n';
            else {
                string r;
                bool done = 0;
                for (int i = n - 1; i >= 0 && !done; i--) {
                    cnt[s[i] - 'a'] -= 1;
                    vector <int> rem(26, 0);
                    int take = 0;
                    for (int j = 0; j < 26; j++) {
                        rem[j] = (k - (cnt[j] % k)) % k;
                        take += (k - (cnt[j] % k)) % k;
                    }
                    if ((n - i - take) >= 0 && (n - i - take) % k == 0) {
                        r = s.substr(0, i);
                        if (n - i - take > 0) {
                            if (s[i] != 'z') {
                                char c = s[i] + 1;
                                r += c;
                                if (rem[s[i] - 'a' + 1]) {
                                    rem[s[i] - 'a' + 1] -= 1;
                                    rem[0] += (n - i - take);
                                }
                                else {
                                    rem[s[i] - 'a' + 1] += k - 1;
                                    rem[0] += (n - i - take - k);
                                }
                                for (int j = 0; j < 26; j++) {
                                    while (rem[j]--) {
                                        r += char('a' + j);
                                    }
                                }
                                done = 1;
                            }
                        }
                        else {
                            char c = '-';
                            for (int j = 0; j < 26; j++) {
                                if (rem[j] && j > int(s[i] - 'a')) {
                                    c = 'a' + j;
                                    rem[j] -= 1;
                                    break;
                                }
                            }
                            if (c != '-') {
                                r += c;
                                for (int j = 0; j < 26; j++) {
                                    while (rem[j]--) {
                                        r += char('a' + j);
                                    }
                                }
                                done = 1;
                            }       
                        }
                    }
                }
                cout << r << '\n';
            }
        }
    }
    return 0;
}