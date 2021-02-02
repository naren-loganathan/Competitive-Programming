#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll diff = 1, num = 0;
    vector <ll> tri(1e3 + 1, 0); //tri[i] = number of 1cm - sided triangles in a triangle of side i
    for (int i = 1; i <= 1000; i++) {
        tri[i] = tri[i - 1] + diff;
        diff += 2;
    }
    vector <ll> a(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    cout << 2 * (a[0] + a[1]) * (a[1] + a[2]) - tri[a[1]] - tri[a[4]] << "\n";
    return 0;
}