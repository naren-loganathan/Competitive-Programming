#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
#define M 1000000007
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector <int> p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        vector <int> subseq;
        subseq.pb(p[0]);
        for(int i = 1; i < n - 1; i++){
            if(p[i] > p[i + 1] && p[i] > p[i - 1]){
                subseq.pb(p[i]);
            }
            if(!(p[i] > p[i + 1]) && !(p[i] > p[i - 1])){
                subseq.pb(p[i]);
            }
        }
        subseq.pb(p[n - 1]);
        cout << subseq.size() << "\n";
        for(int i = 0; i < subseq.size(); i++){
            cout << subseq[i] << ' ';
        }
        cout << "\n";
     }
    return 0;
}