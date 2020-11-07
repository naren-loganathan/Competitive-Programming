#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, h; cin >> n >> h;
    int width = n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > h) {
            width++;
        }
    }
    cout << width << "\n";
    return 0;
}