#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pair <int, int> timings, prev_timings = make_pair(-1, -1);
    int n, h, m, cash = 1, max_c = 1, prev_h, prev;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h >> m;
        timings = make_pair(h, m);
        if(timings != prev_timings){
            if(cash > max_c){
                max_c = cash;
            }
            cash = 1;
            prev_timings = timings;
        }
        else{
            cash++;
        }
    }
    cout << max(max_c, cash) << endl;
    return 0;
}