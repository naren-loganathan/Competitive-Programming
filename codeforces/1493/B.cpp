#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool valid (int hr, int mn, int h, int m) {
    string res = "";
    if (hr < 10) {
        res += '0';
    }
    res += to_string(hr);
    res += ':';
    if (mn < 10) {
        res += '0';
    }
    res += to_string(mn); 
    for (int i = 0; i < 5; i++) {
        if (res[i] == '2') res[i] = '5';
        else if (res[i] == '5') res[i] = '2';
    }
    reverse(res.begin(), res.end());
    int p = stoi(res.substr(0, 2)), q = stoi(res.substr(3, 2));
    if (p < h && q < m) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int h, m; cin >> h >> m;
        string time; cin >> time;
        int hh = stoi(time.substr(0, 2)), mm = stoi(time.substr(3, 2));
        int arr[5], lag = 1e5;
        pair <int, int> ans;
        arr[0] = 0; arr[1] = 1; arr[2] = 2; arr[3] = 5; arr[4] = 8;
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                for (int c = 0; c < 5; c++) {
                    for (int d = 0; d < 5; d++) {
                        int hr = 10 * arr[a] + arr[b], mn = 10 * arr[c] + arr[d];
                        if (valid(hr, mn, h, m) && hr < h && mn < m) {
                            int diff = 0;
                            if (hr == hh) {
                                if (mn >= mm) {
                                    diff = mn - mm;
                                }
                                else {
                                    diff = h * m - (mm - mn);
                                }
                            }
                            else {
                                diff += m - mm + mn;
                                int c = (hh + 1) % h;
                                if (c <= hr) {
                                    diff += (hr - c) * m;
                                }
                                else {
                                    diff += (hr + h - c) * m;
                                }
                            }
                            if (diff < lag) {
                                lag = diff;
                                ans = mp(hr, mn);
                            }
                        }
                    }
                }
            }
        }
        string res = "";
        if (ans.fi < 10) {
            res += '0';
        }
        res += to_string(ans.fi);
        res += ':';
        if (ans.se < 10) {
            res += '0';
        }
        res += to_string(ans.se);
        cout << res << '\n';
    }
    return 0;
}