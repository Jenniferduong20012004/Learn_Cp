#include <bits/stdc++.h>
using namespace std;
long long tinhtoan (long long cur, long long n, long long k, vector <long long> &deBai, vector <long long> &dp){
    if (dp[cur]!= -1){
        return dp[cur];
    }
    long long maxi =0;
    for (long long i = 1; i <= k; i++){
        if (i+ cur > n){
            break;
        }
        maxi = max (maxi, deBai[cur+i] + tinhtoan (cur+i, n, k, deBai, dp));
    }
    dp[cur]= maxi;
    return dp[cur];
}
int main (){
    // freopen ("dpgame2.inp", "r", stdin);
    // freopen ("dpgame2.out", "w", stdout);
    long long n, k;
    cin >> n>> k;
    vector <long long> deBai;
    deBai.push_back (0);
    vector <long long> dp (n+1, -1);
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
    }
    cout << tinhtoan (0, n, k, deBai, dp );
}
