#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, maxi;
    cin >> n>> maxi;
    vector <tuple<long long, long long>> deBai;
    long long sumi =0;
    for (long long i =0; i <n; i++){
        long long a,b; // weight, giatri
        cin >> a>> b;
        sumi += b;
        deBai.push_back (make_tuple (a, b));
    }
    //minimumWeight need to achieve
    vector <long long> weightDp (sumi+1, LLONG_MAX);
    weightDp [0]=0;
    for (long long i =0; i <n; i++){
        long long curWeight = get<0>(deBai[i]);
        long long curVal = get<1>(deBai[i]);
        for (long long j = sumi; j >= curVal; j--){
            if (weightDp[j - curVal] != LLONG_MAX){
                weightDp [j]= min (weightDp[j-curVal]+ curWeight, weightDp[j]);
            }       
        }
    }
    long long ans =0;
    for (long long i =0; i <= sumi; i++){
        if (weightDp[i]<= maxi){
            ans = i;
        }
    }
    cout << ans;
}