#include <iostream>
#include <cmath>
using namespace std;

bool isntPerfectSquare(long double x){
    long double sr = sqrtl(x);
    return sr - floor(sr);
}

bool isPrime(int a){
    if(a <= 1)
        return false;
    if(a <= 3)
        return true;
    if(a % 2 == 0 || a % 3 == 0)
        return false;
    for(int i = 5; i * i <= a; i = i + 6){
        if(a % i == 0 || a % (i + 2) == 0)
            return false; 
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        bool tprime = 0;
        if(!isntPerfectSquare(x)){
            int a = sqrt(x);
            if(isPrime(a))
                tprime = 1;
        }
        if(tprime) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}