#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpbeach.inp", "r", stdin);
    // freopen("dpbeach.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> voOc;
    vector <vector<long long>> dp (n, vector<long long> (51, 1));
    // 1 <=d <=50
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        voOc.push_back (a);
    }
    long long maxi =1;
    for (long long i =1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (capSoCong [i]- capSoCong[j]>=1 && capSoCong [i]- capSoCong[j]<=50){
                dp[i][capSoCong [i]- capSoCong[j]] = max (dp[i][capSoCong [i]- capSoCong[j]], dp[j][capSoCong [i]- capSoCong[j]]+ 1);
                maxi = max (maxi, dp[i][capSoCong [i]- capSoCong[j]]);
            }
        }
    }
    cout << maxi;
}