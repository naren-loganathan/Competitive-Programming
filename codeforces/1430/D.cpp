#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define mp make_pair
#define ub upper_bound

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, cur = 0; 
        string s; 
        cin >> n >> s;
        queue <int> q;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cur++;
            }
            else {
                q.push(cur);
            }
        }
        int deleted = 0, score = 0;
        for (int i = 0; i < n; i++) {
            if (q.empty()) {
                break;
            }
            else {
                q.pop();
                deleted++;
                score++;
                while (!q.empty() && q.front() == i) {
                    q.pop();
                    deleted++;
                }
                deleted++;
            }
        }
        score += (n - deleted + 1) / 2;
        cout << score << "\n";
    }
    return 0;
}