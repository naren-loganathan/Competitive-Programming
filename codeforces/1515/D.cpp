#include <iostream>
#include <vector>
#include <queue>
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
        int n, l, r, cost = 0; 
        cin >> n >> l >> r;
        int dev = l - r;
        vector <int> socks(n);
        for (int i = 0; i < n; i++) {
            int c; cin >> c;
            socks[c - 1] += (i >= l ? -1 : 1);
        }
        for (int i = 0; i < n; i++) {
            if (socks[i] >= 2) {
                if (dev > 0) {
                    int remove = min(socks[i] - (socks[i] % 2), dev);
                    socks[i] -= remove;
                    cost += remove / 2;
                    dev -= remove;
                }
            } else if (socks[i] <= -2) {
                if (dev < 0) {
                    int k = -socks[i];
                    int remove = min(k - (k % 2), -dev);
                    socks[i] += remove;
                    cost += remove / 2;
                    dev += remove;
                }
            }
        }
        if (dev) {
            priority_queue <int> rem_l, rem_r;
            for (int i = 0; i < n; i++) {
                if (socks[i] > 0) {
                    rem_l.push(socks[i]);
                } else if (socks[i] < 0) {
                    rem_r.push((-1) * socks[i]);
                }
            }
            while (!rem_l.empty() && !rem_r.empty()) {
                int left = rem_l.top(), right = rem_r.top();
                rem_l.pop();
                rem_r.pop();
                int rem = min(left, right);
                cost += rem;
                left -= rem;
                right -= rem;
                if (left) rem_l.push(left);
                if (right) rem_r.push(right);
            }
            vector <int> rem;
            while (!rem_l.empty()) {rem.push_back(rem_l.top()); rem_l.pop();}
            while (!rem_r.empty()) {rem.push_back(rem_r.top()); rem_r.pop();}
            for (int i = 0; i < rem.size(); i++) {
                cost += rem[i] / 2;
                if (rem[i] % 2) {
                    cost += 1;
                }
            }
        } else {
            int add = 0;
            for (int i = 0; i < n; i++) {
                add += abs(socks[i]);
            }
            cost += add / 2;
        }
        cout << cost << '\n';
    }
    return 0;
}