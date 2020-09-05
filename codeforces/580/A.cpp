#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, a_prev, max = 1, length = 1;
    cin >> n;
    cin >> a_prev;
    for(int i = 1; i < n; i++){
        cin >> a;
        if(a >= a_prev){
            length++;
            a_prev = a;
        }
        else{
            if(length > max)
                max = length;
            length = 1;
            a_prev = a;
        }
    }
    if(length > max)
        max = length;
    cout << max << endl;
    return 0;
}