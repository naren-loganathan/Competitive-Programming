#include <iostream>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, years = 0;
    cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b *= 2;
        years++;
    }
    cout << years << "\n";
    return 0;
}