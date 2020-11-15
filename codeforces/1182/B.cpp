#include <iostream>
#include <vector>
#include <string>
using namespace std;
     
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
     
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    vector <string> pic(h);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> pic[i];
    }
    int w_plus, h_plus;
    bool yeah = 0;
    for (int i = 1; i < h - 1; i++) {
        if (yeah == 0) {
            for (int j = 1; j < w - 1; j++) {
                if (pic[i][j] == '*') {
                    if (pic[i][j + 1] == '*' && pic[i][j - 1] == '*' && pic[i + 1][j] == '*' && pic[i - 1][j] == '*') {
                        yeah = 1;
                        w_plus = j;
                        h_plus = i;
                        break;
                    }
                }
            }
        }
    }
    if (yeah) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i != h_plus && j != w_plus) {
                    if (pic[i][j] == '*') {
                        yeah = 0;
                    }
                }
            }
        }
        bool done = 0, da = 0;
        for (int i = 0; i < h; i++) {
            if (pic[i][w_plus] == '*') {
                da = 1;
            }
            if (da && pic[i][w_plus] == '.') {
                done = 1;
            }
            if (done && pic[i][w_plus] == '*') {
                yeah = 0;
            }
        }
        done = 0, da = 0;
        for (int i = 0; i < w; i++) {
            if (pic[h_plus][i] == '*') {
                da = 1;
            }
            if (da && pic[h_plus][i] == '.') {
                done = 1;
            }
            if (done && pic[h_plus][i] == '*') {
                yeah = 0;
            }
        }
    }
    cout << (yeah ? "YES" : "NO") << "\n";
    return 0;
}