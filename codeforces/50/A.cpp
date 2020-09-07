#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, number;
    cin >> m >> n;
    if((m * n) % 2 == 0)
        number = m * n / 2;
    else
        number = (m * n - 1) / 2;
    cout << number << endl;
    return 0;
}