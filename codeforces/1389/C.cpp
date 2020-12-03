#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
        string s; cin >> s;
        int n = s.length(), res = n - 2;
        vector <int> freq(10, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 48]++;
        }
        for (int i = 0; i < 10; i++) {
            res = min(res, n - freq[i]);
        }
        for (int i = 0; i < 10; i++) {  //let's create ijij....ijij
            for (int j = 0; j < 10; j++) {
                if (i != j && freq[i] && freq[j]) {
                    int cnt = 0, k = 0;
                    while (s[k] != 48 + i) {
                        if (s[k] == 48 + j) {
                            cnt++;
                        }
                        k++;
                    }
                    int l = n - 1;
                    while (s[l] != 48 + j) {
                        if (s[l] == 48 + i) {
                            cnt++;
                        }
                        l--;
                    }
                    bool ok = 0;
                    for (; k <= l; k++) {
                        if (s[k] == 48 + i) {
                            if (ok) {
                                cnt++;
                            }
                            else {
                                ok = 1;;
                            }
                        }
                        if (s[k] == 48 + j) {
                            if (!ok) {
                                cnt++;
                            }
                            else {
                                ok = 0;
                            }
                        }
                    }
                    res = min(res, n - freq[i] - freq[j] + cnt);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}