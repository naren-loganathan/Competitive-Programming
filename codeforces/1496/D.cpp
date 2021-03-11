#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <int> p(n), v;
    set < pair <int, int> > s[2];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = 0, inc = 0;
    for (int i = 0; i < n; i++) {
        if (v.empty()) {
            v.push_back(i);
        } else {
            if (v.size() == 1) {
                inc = (p[i] > p[v.back()] ? 1 : 0);
                v.push_back(i);
            } else {
                if (inc && p[i] > p[v.back()]) {
                    v.push_back(i);
                } else if (!inc && p[i] < p[v.back()]) {
                    v.push_back(i);
                } else {
                    int x = -v.size(), y = v.front();
                    s[inc].insert(make_pair(x, y));
                    inc = (inc ? 0 : 1);
                    v.clear();
                    v.push_back(i - 1); v.push_back(i);
                }
            }
        }
    }
    int x = -v.size(), y = v.front();
    s[inc].insert(make_pair(x, y));
    if (!s[0].empty() && !s[1].empty()) {
        pair <int, int> p0, p1, p2, p3;
        p0 = *(s[0].begin());
        p1 = *(s[1].begin());
        if (p0.first == p1.first && p0.first % 2) {
            ans = 1;
            s[0].erase(p0);
            s[1].erase(p1);
            if (!s[0].empty()) {
                p2 = *(s[0].begin());
                if (p2.first == p0.first) ans = 0;
            }
            if (!s[1].empty()) {
                p3 = *(s[1].begin());
                if (p3.first == p0.first) ans = 0;
            }
            if (p0.first + p0.second + 1 != p1.second) ans = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}