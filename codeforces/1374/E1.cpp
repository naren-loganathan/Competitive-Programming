#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector <int> a, b, c;
    int al = 0, bl = 0;
    for (int i = 0; i < n; i++) {
        int t, ai, bi;
        cin >> t >> ai >> bi;
        if (ai && bi) {
            c.push_back(t);
            al += 1; bl += 1;
        } else if (ai) {
            a.push_back(t);
            al += 1;
        } else if (bi) {
            b.push_back(t);
            bl += 1;
        }
    }
    if (al < k || bl < k) cout << -1 << '\n';
    else {
        al = k, bl = k;
        int ans = 0;
        sort(a.begin(), a.end(), greater <int> ());
        sort(b.begin(), b.end(), greater <int> ());
        sort(c.begin(), c.end(), greater <int> ());
        while (al > 0 && bl > 0) {
            if (al > 0 && bl > 0) {
                if (!c.empty()) {
                    if (!a.empty() && !b.empty()) {
                        if (a.back() + b.back() > c.back()) {
                            ans += c.back();
                            c.pop_back();
                        } else {
                            ans += a.back() + b.back();
                            a.pop_back(); b.pop_back();
                        }
                    } else {
                        ans += c.back();
                        c.pop_back();
                    }
                } else {
                    ans += a.back() + b.back();
                    a.pop_back(); b.pop_back();
                }
                al -= 1; bl -= 1;
            } else if (al > 0) {
                if (!c.empty()) {
                    if (!a.empty()) {
                        if (c.back() < a.back()) {
                            ans += c.back();
                            c.pop_back();
                        } else {
                            ans += a.back();
                            a.pop_back();
                        }
                    } else {
                        ans += c.back();
                        a.pop_back();
                    }
                } else {
                    ans += a.back();
                    a.pop_back();
                }
                al -= 1;
            } else if (bl > 0) {
                if (!c.empty()) {
                    if (!b.empty()) {
                        if (c.back() < b.back()) {
                            ans += c.back();
                            c.pop_back();
                        } else {
                            ans += b.back();
                            b.pop_back();
                        }
                    } else {
                        ans += c.back();
                        c.pop_back();
                    }
                } else {
                    ans += b.back();
                    b.pop_back();
                }
                bl -= 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}