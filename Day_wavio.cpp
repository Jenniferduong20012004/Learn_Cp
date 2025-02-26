#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpwavio.inp", "r", stdin);
    // freopen("dpwavio.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> wavio;
    vector <vector<long long>> dp (n, vector<long long> (2, 0));
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        wavio.push_back (a);
    }
    long long maxi =1;
    for (long long i =1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (wavio[i]> wavio[j]){
                dp[i][0]= max (dp[i][0], dp[j][0]+1);
            }
            else if (wavio[i]< wavio[j]){
                dp[i][1]= max (dp[i][1],max(dp[j][0]+1, dp[j][1]+1));
                maxi = max (maxi, dp[i][1]);
            }
        }
    }
    if (maxi >1){
        maxi++;
    }
    cout << maxi;
}