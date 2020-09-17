#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string queue;
    int n, t;
    cin >> n >> t;
    cin >> queue;
    for(int i = 0; i < t; i++){
        for(int i = 0; i < n - 1; i++){
            if(queue[i] == 'B' && queue[i + 1] == 'G'){
                queue[i] = 'G';
                queue[i + 1] = 'B';
                i++;
            }
        }
    }
    cout << queue << endl;
    return 0;
}