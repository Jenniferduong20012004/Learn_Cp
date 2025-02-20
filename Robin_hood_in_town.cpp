#include <bits/stdc++.h>
using namespace std;
int main (){
    long long test;
    cin>>test;
    for (long long i =0; i < test; i++){
        long long n;
        cin >> n;
        vector <long long> v;
        long long sumi =0;
        long long maxi = LLONG_MIN;
        for (long long j =0; j < n; j++){
            long long wealth;
            cin >> wealth;
            v.push_back (wealth);
            sumi += wealth;
            maxi = max (wealth, maxi);
        }
        if (n ==1 || n==2){
            cout << -1 << endl;
        }
        else{
            sort (v.begin(), v.end());
            long long low =0, high = 1e6;
            long long ans = high;
            while (low <= high){
                long long mid = low + (high-low)/2;
                long long curSumAvg = (sumi + mid)/n;
                long long des = upper_bound (v.begin(), v.end(), curSumAvg)- v.begin();
                if (des < n/2){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            cout << ans<< endl;
        }
    }
}