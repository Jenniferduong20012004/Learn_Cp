#include <bits/stdc++.h>
using namespace std;
long long legs (long long n, vector <long long> &dp){
    if (n ==2 || n==4){
        return 1;
    }
    else{
        if (dp[n] != -1){
            return dp[n];
        }
        dp[n]= min (1+ legs(n-2, dp), 1+ legs(n-4, dp));
        return dp[n];
    }
}
int main (){
    long long t;
    cin >> t;
    vector <long long> dp (2001,-1);
    for (long long i =0; i < t; i++){
        long long a;
        cin >> a;
        cout << legs (a, dp)<< endl;
    }
}