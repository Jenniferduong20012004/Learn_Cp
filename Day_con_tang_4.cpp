#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dplis2.inp", "r", stdin);
    // freopen("dplis2.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    vector <long long> dp(n+1, LLONG_MAX);
    vector <long long> index (n+1, 0);
    dp[0]= LLONG_MIN;
    for (long long i =0; i < n; i++){
        long long l = upper_bound (dp.begin(), dp.end(), v[i])- dp.begin();
        if (dp[l-1]< v[i]){
            dp[l]= v[i];
            index [l]= i+1;
        }
    }
    long long ans =0;
    for (long long i =0; i <=n ; i++){
        if (dp[i]< LLONG_MAX){
            ans = i;
        }
    }
    cout <<ans<< endl;
    for (long long i =1; i <= ans; i++){
        cout << index[i]<< " ";
    }
}