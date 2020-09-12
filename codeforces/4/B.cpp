#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int d, sumTime, a, b;
    cin >> d >> sumTime;
    vector <int> hours(d), minLimits(d), maxLimits(d);
    for(int i = 0; i < d; i++){
        cin >> minLimits[i] >> maxLimits[i];
        hours[i] = minLimits[i];
    }
    int minTime = accumulate(minLimits.begin(), minLimits.end(), 0);
    int maxTime = accumulate(maxLimits.begin(), maxLimits.end(), 0);
    if(sumTime >= minTime && sumTime <= maxTime){
        cout << "YES" << "\n";
        for(int i = 0; i < d; i++){
            if(sumTime - minTime > 0){
                if(sumTime - minTime > maxLimits[i] - minLimits[i]){
                    hours[i] += (maxLimits[i] - minLimits[i]);
                    minTime += (maxLimits[i] - minLimits[i]);
                }
                else{
                    hours[i] += (sumTime - minTime);
                    break;
                }
            }
            else{
                break;
            }
        }
        for(int i = 0; i < d; i++)
            cout << hours[i] << " ";
    }
    else{
        cout << "NO";
    }
    cout << endl;
    return 0;
}