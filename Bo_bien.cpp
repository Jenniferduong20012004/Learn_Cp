#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpbeach.inp", "r", stdin);
    // freopen("dpbeach.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> voOc;
    vector <long long> dp (n, 1), dpBack (n,1);
    // 1 <=d <=50
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        voOc.push_back (a);
    }
    long long maxi =1;
    for (long long i =n-2; i >=0; i--){
        for (long long j =n-1; j >i; j--){
            if (voOc[i] <  voOc[j]){
                dp[i] = max (dp[i], dp[j]+1);          
        }
    }
    }
    for (long long i =1; i <n; i++){
        for (long long j = 0; j <i; j++){
            if (voOc[i] < voOc[j]){
                dpBack[i] = max (dpBack[i], max(dpBack[j]+1, dp[j]+1));
            }
        }
    }
    for (long long i =0; i <n; i++){
        maxi = max (maxi, max(dp[i], dpBack[i]));
    }
    cout << maxi;
}