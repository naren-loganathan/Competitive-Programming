#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, hours = 0, went_out = 0;
    cin >> a >> b;
    while(a != 0){
        a--;
        went_out++;
        if(went_out == b){
            went_out = 0;
            a++;
        }
        hours++;
    }
    cout << hours << endl;
    return 0;
}