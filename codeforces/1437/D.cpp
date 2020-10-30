#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, height = 1, length = 0; 
        cin >> n;
        vector <int> a(n), segs;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                segs.push_back(length);
                length = 1;
            }
            else {
                length++;
            }
        }
        segs.push_back(length);
        int i = 1, max_children = segs[0], new_level = 0, children = 0;
        while (i < segs.size()) {
            new_level += segs[i];
            children++;
            if (children == max_children) {
                height++;
                max_children = new_level;
                children = 0;
                new_level = 0;
            }
            i++;
        }
        if (i == segs.size() && new_level != 0) {
            height++;
        }
        cout << height << "\n";
    }
    return 0;
}