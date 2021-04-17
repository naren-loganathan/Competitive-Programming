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
    int arr_x[] = {1, 16, 128, 1024, 16384, 131072, 1048576, 16777216, 134217728}; 
    int arr_y[] = {1, 27, 243, 2187, 19683, 177147, 1594323, 14348907, 129140163}; 
    while (t--) {
        int a, b, c, x = 1, y = 1; 
        cin >> a >> b >> c;
        for (int i = 1; i < c; i++) {
            x *= 10;
            y *= 10;
        }
        x *= arr_x[a - c];
        y *= arr_y[b - c];
        cout << x << ' ' << y << '\n';
    }
    return 0;
}