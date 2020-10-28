#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, cnt0 = 0, cnt1 = 0; 
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            (a[i] ? cnt1++ : cnt0++);
        }
        if (cnt0 >= cnt1) {
            cout << cnt0 << "\n";
            for (int i = 0; i < n; i++) {
                if (!a[i]) {
                    cout << a[i] << " ";
                }
            }
            cout << "\n";
        }
        else {
            if (cnt1 % 2) {
                cnt1--;
            }
            cout << cnt1 << "\n";
            for (int i = 0; i < n; i++) {
                if (a[i] && cnt1) {
                    cout << a[i] << " ";
                    cnt1--;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}