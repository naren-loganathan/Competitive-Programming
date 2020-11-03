#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define fi first
#define se second
#define mp make_pair

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool possible = 1;
    int min_index, min_value = 1e9 + 1, result;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_value) {
            min_value = a[i];
            min_index = i;
        }
    }
    if (a[0] == min_value && a[n - 1] == min_value) {
        int i = n - 1;
        while (a[i] == min_value) {
            i--;
            if (i == -1) {
                break;
            }
        }
        i++;
        min_index = i;
    }
    for (int i = 1; i < n; i++) {
        if (a[(min_index + i) % n] < a[(min_index + i - 1) % n]) {
            possible = 0;
            break;
        }
    }
    if (possible) {
        cout << (min_index ? n - min_index : min_index) << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
    return 0;
}