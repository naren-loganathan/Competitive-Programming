#include <iostream>
#include <string>
using namespace std;

typedef long long int ll;
#define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, n, max = 0, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        sum += (b - a);
        if(sum > max){
            max = sum;
        }
    }
    cout << max << endl;
    return 0;
}