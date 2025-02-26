#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpbatman.inp", "r", stdin);
    // freopen("dpbatman.out", "w", stdout);
    long long t;
    cin >> t;
    for (long long test =0; test < t; test++){
        long long n,m;
        cin >> n>>m;
        vector <long long> dinhNui;
        vector <long long> dp (n, 1);
        for (long long i =0; i < n; i++){
            long long a;
            cin >> a;
            dinhNui.push_back (a);
        }
        m-=1;
        long long maxi =0;
        for (long long i =1; i < n; i++){
            for (long long j =0; j < i; j++){
                if (j == m){
                    dp[i] =max (dp[i], dp[j]+1);
                }
                else{
                    if (dinhNui[i]< dinhNui[j]){
                        dp[i] =max (dp[i], dp[j]+1);
                    }
                }
            }
            maxi = max (maxi, dp[i]);
        }
        cout << maxi<< endl;
    }
}