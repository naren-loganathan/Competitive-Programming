#include <iostream>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, n;
    bool divisible = 0;
    string s;
    cin >> a >> b >> n;
    a *= 10;
    for(int i = 0; i < 10; i++){
        if((a + i) % b == 0){
            a += i;
            divisible = 1;
            break;
        }
    }
    if(divisible){
        cout << a;
        for(int i = 1; i < n; i++){
            cout << "0";
        }
    }
    else{
        cout << "-1";
    }
    cout << endl;
    return 0;
}