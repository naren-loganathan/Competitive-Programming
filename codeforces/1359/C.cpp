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
    int test_cases; cin >> test_cases;
    while (test_cases--) {
        ll h, c, t, answer = 1; 
        cin >> h >> c >> t;
        if (h != t) {
            if (h - t >= t - c) {
                answer = 2;
            }
            else {  //HCHCHCHCHC... >= t
                ll lo = 0, hi = 1e9;
                while (lo < hi) {
                    ll mid = (lo + hi) >> 1;
                    ll cups = mid + (lo == mid);
                    if (cups * (c + h) + h >= (2 * cups + 1) * t) {
                        (lo == mid ? lo++ : lo = mid);
                    }
                    else {
                        (lo == mid ? hi-- : hi = mid - 1);
                    }
                }
                answer = 2 * lo + 1;
                ll d1 = lo * (c + h) + h - (2 * lo + 1) * t;
                ll d2 = (2 * lo + 3) * t - (lo + 1) * (c + h) - h;
                if (d1 * (2 * lo + 3) > d2 * (2 * lo + 1)) {
                    answer += 2;
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}