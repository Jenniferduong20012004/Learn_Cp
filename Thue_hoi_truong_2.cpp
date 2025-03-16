#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dprentht2.inp", "r", stdin);
    // freopen("dprentht2.out", "w", stdout);
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> thoigianthue;
    vector <long long> dp (n+1, LLONG_MAX);
    dp[0]= LLONG_MIN;
    for (long long i =0; i < n; i++){
        long long a,b;
        cin >> a>> b;
        thoigianthue.push_back (make_tuple(a, b));
    }
    sort (thoigianthue.begin(), thoigianthue.end());
    for (long long i =0; i < n; i++){
        long long des = upper_bound (dp.begin(), dp.end(), get <0> (thoigianthue[i]))- dp.begin();
        if (dp[des-1]< get<0>(thoigianthue[i]) && dp[des]> get<1>(thoigianthue[i])){
            dp[des]= get<1>(thoigianthue[i]);
        }
    }
    long long res =0;
    for (long long i =1; i <=n; i++){
        if (dp[i]== LLONG_MAX){
            break;
        }
        // cout << dp[i]<< " ";
        res++;
    }
    cout << res;
}