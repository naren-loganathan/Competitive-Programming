#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, count = 0;
    double x, y, x0, y0;
    set <double> slopes;
    cin >> n >> x0 >> y0;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(!(x - x0))
            count = 1;
        else{
            slopes.insert((y - y0) / (x - x0));
        }
    }
    cout << slopes.size() + count << endl;
    return 0;
}