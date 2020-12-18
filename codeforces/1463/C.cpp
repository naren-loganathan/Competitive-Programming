    #include <iostream>
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
            ll n, x, t, cnt = 0; 
            cin >> n;
            ll pos = 0, dest = 0, arrival_time = 0, starting_time = 0, starting_pos = 0;
            ll prev_pos = 1e9 + 1, prev_time = -1e9 - 1, prev_dest = -1e9 - 1;
            bool still = 1;
            for (int i = 0; i < n; i++) {
                cin >> t >> x;
                if (t >= arrival_time) {
                    pos = dest;
                    still = 1;
                }
                else {
                    if (pos > dest) {
                        pos = starting_pos - (t - starting_time);
                    }
                    else {
                        pos = starting_pos + (t - starting_time);
                    }
                }
                if ((prev_dest <= pos && prev_dest >= prev_pos) || (prev_dest <= prev_pos && prev_dest >= pos)) {
                    cnt++;
                }
                if (still) {
                    starting_pos = pos;
                    starting_time = t;
                    arrival_time = t + abs(x - pos);
                    dest = x;
                    still = 0;
                }
                prev_pos = pos; prev_time = t; prev_dest = x;
            }
            if ((prev_dest >= dest && prev_dest <= pos) || (prev_dest <= dest && prev_dest >= pos)) {
                cnt++;
            }
            cout << cnt << "\n";
        }
        return 0;
    }