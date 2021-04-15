#include <iostream>
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
        int p, f; cin >> p >> f;
        int S, W; cin >> S >> W;
        int s, w; cin >> s >> w;
        int ans = 0;
        for (int i = 0; i * s <= p && i <= S; i++) {
            int rem_S = S - i;
            int rem_W = W - min(W, (p - i * s) / w);
            int follower = f;
            if (s >= w) {
                int remove = min(rem_W, follower / w);
                follower -= w * remove;
                rem_W -= remove;
                rem_S -= min(rem_S, follower / s);
            } else {
                int remove = min(rem_S, follower / s);
                follower -= s * remove;
                rem_S -= remove;
                rem_W -= min(rem_W, follower / w);
            }
            ans = max(ans, S + W - rem_S - rem_W);
        }
        cout << ans << '\n';
    }
    return 0;
}