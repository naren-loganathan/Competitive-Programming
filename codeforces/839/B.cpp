#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool possible = 1;
    int n, k; cin >> n >> k;
    vector <int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater <int> ());
    int mid = 0;    //number of filled middle rows
    for (int i = 0; i < k; i++) {
        if (a[i] >= 4) {
            if (mid < n) {
                if (mid + (a[i] / 4) > n) {
                    a[i] -= ((n - mid) * 4);
                    mid = n;
                }
                else {
                    mid += (a[i] / 4);
                    a[i] %= 4;
                }
            }
        }
    }
    int sides = 0, bleh = 0, lim = n - mid, single = 0, cnt = 0, full = 0;  //number of filled side rows, bleh -> XXOO, cnt -> OOOX
    for (int i = 0; i < k; i++) {
        if (a[i] >= 2) {
            if (sides < 2 * n) {
                if (sides + (a[i] / 2) > 2 * n) {
                    a[i] -= ((2 * n - sides) * 2);
                    sides = 2 * n;
                }
                else {
                    sides += (a[i] / 2);
                    a[i] %= 2;
                }
            }
        }
    }
    sort(a.begin(), a.end(), greater <int> ());
    for (int i = 0; i < k; i++) {
        if (a[i] == 2) {
            if (sides < 2 * n) {
                sides++;
                a[i] = 0;
            }
        }
        else if (a[i] == 1) {
            if (sides < 2 * n) {
                sides++;
                a[i] = 0;
            }
        }
    }
    sort(a.begin(), a.end(), greater <int> ());
    int count1 = 0, count2 = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == 1) {
            count1++;
        }
        if (a[i] == 2) {
            count2++;
        }
    }
    if (count2 <= lim) {
        int rem = (lim - count2) * 2 + (count2);
        if (rem < count1) {
            possible = 0;
        }
    }
    else {
        int rem = lim - (count2 - lim) * 2;
        if (rem < count1) {
            possible = 0;
        }
    }
    cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}