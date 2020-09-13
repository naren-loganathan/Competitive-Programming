#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1, a2, minutes = 0;
    cin >> a1 >> a2;
    while(a1 > 0 && a2 > 0){
        if(a1 == 1 && a2 == 1)
            break;
        minutes++;
        if(a1 >= a2){
            a1 -= 2;
            a2 += 1;
        }
        else{
            a1 += 1;
            a2 -= 2;
        }
    }
    cout << minutes << endl;
    return 0;
}