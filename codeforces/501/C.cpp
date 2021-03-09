#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

map <int, int> s;
map <int, int> degree;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    set < pair <int, int> > v;
    for (int i = 0; i < n; i++) {
        int degree_v, s_v;
        cin >> degree_v >> s_v;
        s[i] = s_v;
        degree[i] = degree_v;
        if (degree_v) v.insert(mp(degree_v, i));
    }
    vector < pair <int, int> > edges;
    while (!v.empty()) {
        pair <int, int> ver = *(v.begin());
        if (ver.fi == 1) {
            v.erase(ver);
            edges.push_back(mp(ver.se, s[ver.se]));
            pair <int, int> dest = mp(degree[s[ver.se]], s[ver.se]);
            s[s[ver.se]] ^= ver.se;
            degree[s[ver.se]] -= 1;
            v.erase(dest);
            if (degree[s[ver.se]]) v.insert(mp(degree[s[ver.se]], s[ver.se]));
        }
    }
    cout << edges.size() << '\n';
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].fi << ' ' << edges[i].se << '\n';
    }
    return 0;
}