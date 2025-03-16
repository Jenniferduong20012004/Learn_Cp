#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpsancorp2.inp", "r", stdin);
    // freopen("dpsancorp2.out", "w", stdout);
    long long test ;
    cin >> test;
    for (long long te =0; te < test; te++){
        long long n;
        cin >> n;
        vector <tuple <long long, long long ,long long>> v (n+1);
        for (long long i =1; i <=n; i++){
            long long a,b,c;
            cin >>a>>b>>c;
            b +=a-1;
            v[i]=make_tuple (a,b,c);
        }
        sort(v.begin()+1, v.end(), [](const auto &a, const auto &b){
            if (get<1> (a)== get <1> (b)){
                return get<0> (a)< get <0> (b);
            }
            else{
                return get<1> (a)< get <1> (b);
            }
        });
    map<long long , long long> dp;
    dp[0] = 0;
    for (int i = 1 ; i <=n ; i++) {
        dp[get <1>(v[i])] = dp[get <1>(v[i-1])];
        auto it = dp.lower_bound(get <0>(v[i]));
        it--;   
        dp[get <1>(v[i])] = max(dp[get <1>(v[i])], get <2>(v[i]) + it->second);
        // cout << dp[get<1>(v[i])]<< endl;
    }
    cout << dp[get <1>(v[n])]<< endl;
    }
    return 0;
}