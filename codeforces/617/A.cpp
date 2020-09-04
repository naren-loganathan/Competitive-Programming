#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, min_steps = 0;
    cin >> x;
    for(int i = 5; i > 0; i--){
        min_steps += x / i;
        x %= i;
        if(x == 0)
            break;
    }
    cout << min_steps << endl;
    return 0;
}