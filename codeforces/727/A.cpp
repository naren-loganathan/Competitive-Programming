#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
             
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

bool reached = 0;

void dfs (ll a, ll b) {
    if (a == b) {
        reached = 1;
        return;
    }
    else if (a > b) {
        return;
    }
    else {
        dfs(2 * a, b);
        dfs(10 * a + 1LL, b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b; cin >> a >> b;
    dfs(a, b);
    if (reached) {
        cout << "YES" << "\n";
        vector <ll> path;
        while (b >= a) {
            path.push_back(b);
            b = (b % 2 ? (b - 1) / 10 : b / 2);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    return 0;
}