#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

vector < set <int> > adj(2e5);
vector <int> pre(2e5), vis(2e5);
ll cnt;
int cv1, cv2;

void cycle_dfs(int u, int parent) {
    vis[u] = 1; pre[u] = parent;
    set <int> :: iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); it++) {
        if (*it != pre[u]) {
            if (vis[*it]) {
                cv1 = u;
                cv2 = *it;
            } else {
                cycle_dfs(*it, u);
            }
        }
    }
}

void count_dfs(int u) {
    cnt += 1; vis[u] = 1;
    set <int> :: iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); it++) {
        if (!vis[*it]) {
            count_dfs(*it);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        cycle_dfs(0, -1);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }
        adj[cv1].erase(cv2);
        adj[cv2].erase(cv1);
        int cur = cv1;
        bool p12 = false, p21 = false;
        while (pre[cur] != -1) {
            cur = pre[cur];
            if (cur == cv2) {
                p21 = true; break;
            }
        }
        cur = cv2;
        while (pre[cur] != -1) {
            cur = pre[cur];
            if (cur == cv1) {
                p12 = true; break;
            }
        }
        if (p12) {
            cur = cv2;
            while (cur != cv1) {
                adj[pre[cur]].erase(cur);
                adj[cur].erase(pre[cur]);
                cur = pre[cur];
            }
        } else if (p21) {
            cur = cv1;
            while (cur != cv2) {
                adj[pre[cur]].erase(cur);
                adj[cur].erase(pre[cur]);
                cur = pre[cur];
            }
        } else {
            while (pre[cv1] != -1) {
                int nxt = pre[cv1], cur = cv1;
                adj[nxt].erase(cur);
                adj[cur].erase(nxt);
                cv1 = nxt;
            }
            while (pre[cv2] != -1) {
                int nxt = pre[cv2], cur = cv2;
                adj[nxt].erase(cur);
                adj[cur].erase(nxt);
                cv2 = nxt;
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt = 0;
                count_dfs(i);
                ans += cnt * (cnt - 1) / 2 + cnt * (n - cnt);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}