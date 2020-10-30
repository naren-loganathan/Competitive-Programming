#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, max_votes = 0; 
    cin >> n >> m;
    vector < vector <int> > polls(m, vector <int> (n));
    vector <int> victors(n, 0);
    for (int i = 0; i < m; i++) {
        max_votes = 0;
        for (int j = 0; j < n; j++) {
            cin >> polls[i][j];
            max_votes = max(max_votes, polls[i][j]);
        }
        for (int j = 0; j < n; j++) {
            if (polls[i][j] == max_votes) {
                victors[j]++;
                break;
            }
        }
    }
    max_votes = 0;
    for (int i = 0; i < n; i++) {
        max_votes = max(max_votes, victors[i]);
    }
    for (int i = 0; i < n; i++) {
        if (victors[i] == max_votes) {
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}