#include <iostream>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[7]; 
    cin >> n;
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }
    int sum = 0, i = 0;
    while (sum < n) {
        sum += a[i % 7];
        i++;
    }
    i--;
    cout << (i % 7) + 1 << "\n";
    return 0;
}