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
    int n, m; cin >> n >> m;
    vector <string> snake(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % 2 == 0) {
                snake[i].push_back('#');
            }
            else {
                snake[i].push_back('.');
            }
        }
        if (i % 2) {
            ((i - 1) % 4 == 0 ? snake[i][m - 1] = '#' : snake[i][0] = '#');
        }
        cout << snake[i] << "\n";
    }
    return 0;
}

//still lazy