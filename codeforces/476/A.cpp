#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, min_moves;
    cin >> n >> m;
    min_moves = n / 2;
    if(n % 2 != 0)
        min_moves++;
    for(int i = min_moves; i <= n + 1; i++){
        if(i == n + 1){
            cout << -1 << "\n";
            break;
        }
        if(i % m == 0){
            cout << i << "\n";
            break;
        }

    }
    return 0;
}