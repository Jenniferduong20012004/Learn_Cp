#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpsmax.inp", "r", stdin);
    // freopen("dpsmax.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> keo;
    vector <long long> dp (n, 0);
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        keo.push_back (a);
    }
    long long maxi =0;
    dp[0]= keo[0];
    for (long long i =1; i < n; i++){
        dp[i] = keo[i];
        for (long long j =0; j < i; j++){
            if (keo[i]>= keo[j]){
                dp[i]= max (dp[i], dp[j]+ keo[i]);
            }
        }
        maxi = max (maxi, dp[i]);
    }
    cout << maxi;
}