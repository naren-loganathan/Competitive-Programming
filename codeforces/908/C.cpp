#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, r; 
    scanf("%d %d", &n, &r);
    vector <int> x(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    vector <ld> y(n);
    for (int i = 0; i < n; i++) {
        ld d = r;
        for (int j = 0; j < i; j++) {
            if (abs(x[i] - x[j]) <= 2 * r) {
                ld base = abs(x[i] - x[j]);
                ld height = sqrt(4 * r * r - base * base);
                d = max(d, y[j] + height);
            }
        }
        y[i] = d;
    }
    for (int i = 0; i < n; i++) {
        printf("%0.7Lf ", y[i]);
    }
    printf("\n");
    return 0;
}