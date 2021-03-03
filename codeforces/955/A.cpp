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
    int hh, mm; cin >> hh >> mm;
    int H, D, C, N;
    cin >> H >> D >> C >> N;
    float h, d, c, n, answer = 0;
    h = H; d = D; c = C; n = N;
    if (hh < 20) {
        answer = c * ceil(h / n);
        float wait = 0, minutes = 0;
        minutes = 60 - mm;
        minutes += 60 * (20 - hh - 1);
        h += d * minutes;
        answer = min(answer, float(0.8 * c * ceil(h / n)));
    }
    else {
        c *= 0.8;
        answer = c * ceil(h / n);
    }
    printf("%0.4f\n", answer);
    return 0;
}