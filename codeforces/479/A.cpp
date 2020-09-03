#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, possibilities[6];
    cin >> a >> b >> c;
    possibilities[0] = a + b + c;
    possibilities[1] = a * b * c;
    possibilities[2] = (a + b) * c;
    possibilities[3] = a + (b * c);
    possibilities[4] = (a * b) + c;
    possibilities[5] = a * (b + c);
    sort(possibilities, possibilities + 6);
    cout << possibilities[5] << endl;
    return 0;
}