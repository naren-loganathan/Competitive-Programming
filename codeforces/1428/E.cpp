#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

ll square (ll i) {
    return i * i;
}

ll time (ll length, ll num_cuts) {
    ll piece_length = length / num_cuts;
    ll extra = length - num_cuts * piece_length;
    return ((num_cuts - extra) * square(piece_length) + extra * square(piece_length + 1));
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, k, a, min_time = 0;
    cin >> n >> k;
    priority_queue < pair <ll, pair <ll, ll> > > carrots;
    for (int i = 0; i < n; i++) {
        cin >> a;
        min_time += a * a;
        carrots.push(mp(time(a, 1) - time(a, 2), mp(a, 2)));
    }
    for (int i = 0; i < k - n; i++) {
        min_time -= carrots.top().first;
        ll x = carrots.top().second.first;
        ll y = carrots.top().second.second;
        carrots.pop();
        carrots.push(mp(time(x, y) - time(x, y + 1), mp(x, y + 1)));
    }
    cout << min_time << "\n";
    return 0;
}