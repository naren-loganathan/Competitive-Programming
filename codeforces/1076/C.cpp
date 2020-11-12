#include <iostream>
using namespace std;
     
typedef long long int ll;
typedef long double ld;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int d; cin >> d;
        ld a, b;
        if (d != 0 && d < 4) {
            printf("N\n");
        }
        else {
            ld e = d;
            if (d == 0) {
                a = 0; b = 0;
            }
            else if (d == 4) {
                a = 2; b = 2;
            }
            else {
                ld delta = 1;
                a = 1; b = d - 1;
                for (int i = 0; i < 50; i++) {
                    while (a * b < d) {
                        a += delta;
                        b -= delta;
                    }
                    a -= delta;
                    b += delta;
                    delta /= 2;
                }
            }
            printf("Y %0.9Lf %0.9Lf\n", a, b);
        }
    }
    return 0;
}