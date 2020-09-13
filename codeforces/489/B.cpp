#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, m = 0, a[101] = {}, b[102] = {}, boy, girl, num_pairs = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> boy;
        a[boy]++;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> girl;
        b[girl]++;
    }
    for(int i = 1; i <= 100; i++){
        if(a[i] > 0){
            if(b[i - 1] > 0){
                if(a[i] > b[i - 1]){
                    num_pairs += b[i - 1];
                    a[i] -= b[i - 1];
                    b[i - 1] = 0;
                }
                else{
                    num_pairs += a[i];
                    b[i - 1] -= a[i];
                    a[i] = 0;
                }
            }
            if(b[i] > 0 && a[i] > 0){
                if(a[i] > b[i]){
                    num_pairs += b[i];
                    a[i] -= b[i];
                    b[i] = 0;
                }
                else{
                    num_pairs += a[i];
                    b[i] -= a[i];
                    a[i] = 0;
                }
            }
            if(b[i + 1] > 0 && a[i] > 0){
                if(a[i] > b[i + 1]){
                    num_pairs += b[i + 1];
                    a[i] -= b[i + 1];
                    b[i + 1] = 0;
                }
                else{
                    num_pairs += a[i];
                    b[i + 1] -= a[i];
                    a[i] = 0;
                }
            }
        }
    }
    cout << num_pairs << endl;
    return 0;
}