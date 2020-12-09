#include <iostream>
#include <vector>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define N 150005

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, cnt = 0; cin >> n;
    vector <int> freq(N, 0);
    for (int i = 0; i < n; i++) {
        cin >> a;
        freq[a]++;
    }
    vector <bool> present(N, 0);
    for (int i = N - 1; i > 0; i--) {
        if (freq[i] >= 3) {
            present[i] = 1;
            present[i - 1] = 1;
            present[i + 1] = 1;
        }
        if (freq[i] == 2) {
            present[i] = 1;
            if (present[i + 1] == 0) {
                present[i + 1] = 1;
            }
            else {
                present[i - 1] = 1;
            }
        }
        if (freq[i] == 1) {
            if (present[i + 1] == 0) {
                present[i + 1] = 1;
            }
            else if (present[i] == 0) {
                present[i] = 1;
            }
            else {
                present[i - 1] = 1;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        if (present[i]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}