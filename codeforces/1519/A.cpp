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
        bool poss = 1;
        int r, b, d; cin >> r >> b >> d;
        int packet_num = min(r, b);
        int max_fill = (max(r, b) + packet_num - 1 ) / packet_num;
        if (max_fill - 1 > d) {
            poss = 0;
        }
        cout << (poss ? "YES" : "NO") << '\n';
    }
    return 0;
}