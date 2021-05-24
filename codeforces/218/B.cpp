#include <iostream>
#include <vector>
#include <set>
using namespace std;            

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m; cin >> n >> m;
    multiset <ll> min_s, max_s;
    ll min_ans = 0, max_ans = 0;
    while (m--) {
        ll a; cin >> a;
        min_s.insert(a);
        max_s.insert(a * (-1));
    }
    while (n--) {
        ll curr_min = *(min_s.begin());
        min_ans += curr_min;
        min_s.erase(min_s.find(curr_min));
        if (curr_min > 1) {
            min_s.insert(curr_min - 1);
        }
        ll curr_max = *(max_s.begin());
        max_ans -= curr_max;
        max_s.erase(max_s.find(curr_max));
        if (curr_max < -1) {
            max_s.insert(curr_max + 1);
        }
    }
    cout << max_ans << ' ' << min_ans << '\n';
    return 0;
}