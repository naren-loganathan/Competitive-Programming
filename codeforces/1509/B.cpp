#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
        int n; cin >> n;
        deque <int> t, m;
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'T') {
                t.push_back(i);
            } else {
                m.push_back(i);
            }
        }
        if (t.size() != (2 * n) / 3) {
            cout << "NO" << '\n';
        } else {
            bool poss = 1;
            deque <int> last_idx;
            while (!m.empty()) {
                if (t.front() > m.front()) {
                    poss = 0; break;
                } else {
                    t.pop_front();
                    last_idx.push_back(m.front());
                    m.pop_front();
                }
            }
            if (poss) {
                while (!last_idx.empty()) {
                    if (t.front() < last_idx.front()) {
                        poss = 0; break;
                    } else {
                        last_idx.pop_front();
                        t.pop_front();
                    }
                }
            }
            cout << (poss ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}