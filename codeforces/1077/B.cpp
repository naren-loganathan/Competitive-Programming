#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector <int> flats(n);
    int min = 0;
    for(int i = 0; i < n; i++){
        cin >> flats[i];
    }
    for(int i = 1; i < n - 1; i++){
        if(flats[i] == 0 && flats[i + 1] == 1 && flats[i - 1] == 1){
            min++;
            flats[i + 1] = 0;
        }
    }
    cout << min << endl;
    return 0;
}