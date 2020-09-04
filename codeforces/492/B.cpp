#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, x;
    double min_light_radius;
    vector <int> positions;
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> x;
        positions.push_back(x);
    }
    sort(positions.begin(), positions.end());
    int end = positions[positions.size() - 1];
    for(int i = positions.size() - 1; i > 0; i--){
        positions[i] = positions[i] - positions[i - 1];
    }
    positions[0] *= 2;
    sort(positions.begin(), positions.end());
    min_light_radius = positions[positions.size() - 1] / 2.00;
    if(min_light_radius < (l - end)){
        min_light_radius  = l - end;
    }
    cout << fixed << setprecision(10) << min_light_radius << endl;
    return 0;
}