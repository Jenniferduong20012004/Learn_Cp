#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000;
long long tinhtoan (long long cur, long long n, vector <long long> &dp, vector <long long> &deBai){
    if (cur >= n){
        return 0;
    }
    else if (cur == n-1){
        return deBai[cur];
    }
    else{
        if (dp[cur]!=-1){
            return dp[cur];
        }
        return dp[cur]= max (deBai[cur]+ tinhtoan (cur+2, n,dp,deBai), tinhtoan (cur+1, n,dp,deBai));
    }
}
int main(){
    // freopen("dpprincess.inp", "r", stdin);
    // freopen("dpprincess.out", "w", stdout);
    long long testcase;
    cin >> testcase;
    for (long long i=0; i < testcase; i++){
        long long n;
        cin >> n;
        vector <long long> deBai;
        for (long long j =0; j < n; j++){
            long long a;
            cin >> a;
            deBai.push_back (a);
        }
        vector <long long> dp (n, -1);
        cout << tinhtoan (0,n,dp,deBai)<< endl;
    }
    
}
// 1 2 3 4 5
//