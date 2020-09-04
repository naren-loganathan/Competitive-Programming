#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float n, m, a, b;
    cin >> n >> m >> a >> b;
    int min_sum = n * a;
    if(b / m < a){
        if(b > (n - floor(n / m) * m) * a)
            min_sum = floor(n / m) * b + (n - floor(n / m) * m) * a;
        else
            min_sum = ceil(n / m) * b;
    }
    cout << min_sum << endl;
    return 0;
}