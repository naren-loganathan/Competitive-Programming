#include <iostream>
#include <set>
#include <algorithm>
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
        int n, W; cin >> n >> W;
        multiset <int> w;
        for (int i = 0; i < n; i++) {
            int width; cin >> width;
            w.insert(width);
        }
        int lvl = 1, curr = 0;
        while (!w.empty()) {
            int req = W - curr, val;
            multiset <int> :: iterator it;
            it = w.lower_bound(req);
            //cout << req << ' ';
            if (it == w.end()) {
                val = *(w.rbegin());
                curr += val;
            } else if (*(w.begin()) > req) {
                val = *(w.rbegin());
                curr = val; lvl += 1;
            } else {
                if (*it > req) it--;
                val = *it;
                curr += val;
            }
            w.erase(w.find(val));
        }
        cout << lvl << '\n';
    }
    return 0;
}