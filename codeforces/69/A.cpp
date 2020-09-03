#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f_x = 0, f_y = 0, f_z = 0, n, x, y, z;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        f_x += x;
        f_y += y;
        f_z += z;
    }
    if(f_x == 0 && f_y == 0 && f_z == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}