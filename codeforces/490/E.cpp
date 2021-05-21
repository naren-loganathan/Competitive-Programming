#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    bool poss = true;
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < a[0].length(); i++) {
        if (a[0][i] == '?') a[0][i] = (i ? '0' : '1');
    }
    for (int i = 1; i < n; i++) {
        if (a[i].length() < a[i - 1].length()) {
            poss = false; break;
        } else if (a[i].length() > a[i - 1].length()) {
            for (int j = 0; j < a[i].length(); j++) {
                if (a[i][j] == '?') a[i][j] = (j ? '0' : '1');
            }
        } else {
            string s = a[i], t = a[i];
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '?') {
                    s[j] = '9';
                }
            }
            if (stoi(s) <= stoi(a[i - 1])) {
                poss = false; break;
            } else {
                vector <int> idx;
                bool fixed = false;
                int curr = -1;
                for (int j = 0; j < a[i].length(); j++) {
                    if (a[i][j] == '?') {
                        idx.push_back(j); a[i][j] = a[i - 1][j];
                    } else if (a[i][j] < a[i - 1][j]) {
                        while (true) {
                            curr = idx.back();
                            if (a[i][curr] != '9') {
                                a[i][curr] += 1;
                                break;
                            } else {
                                idx.pop_back();
                            }
                        }
                        fixed = true; break;
                    } else if (a[i][j] > a[i - 1][j]) {
                        fixed = true; curr = j; break;
                    }
                }
                if (!fixed) {
                    while (true) {
                        curr = idx.back();
                        if (a[i][curr] != '9') {
                            a[i][curr] += 1;
                            break;
                        } else {
                            idx.pop_back();
                        }
                    }
                }
                for (int j = curr + 1; j < a[i].length(); j++) {
                    if (t[j] == '?') a[i][j] = '0';
                }
            }
        }
    }
    if (poss) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}