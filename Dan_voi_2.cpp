#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpvoi2.inp", "r", stdin);
    // freopen("dpvoi2.out", "w", stdout);
    long long a, b;
    vector <tuple<long long, long long, long long>> voi;
    long long ii =1;
    while (cin >> a >> b && (a != 0 || b != 0)){
        voi.push_back (make_tuple(a, b, ii));
        ii++;
    }
    sort (voi.begin(), voi.end(), [](auto const &a, auto const &b){
        if (get <0> (a) !=  get<0> (b)){
            return get <0> (a) < get<0> (b);
        }
        else{
            return get <1> (a) > get<1> (b);
        }
    });
    vector <long long> dp (ii, LLONG_MAX);
    dp[0]= LLONG_MIN;
    vector <long long> index (ii, LLONG_MAX);
    for (long long i =voi.size()-1; i >= 0; i--){
        long long curSmart = get <1> (voi[i]);
        long long des = upper_bound (dp.begin(), dp.end(), curSmart)- dp.begin();
        if (dp[des-1]< curSmart){
            if (dp[des]== LLONG_MAX){
                index[des] = get <2> (voi[i]);
            }
            dp[des]= curSmart;
        }
    }
    long long ans =0;
    for (long long i =1; i <= voi.size(); i++){
        if (dp[i]== LLONG_MAX){
            break;
        }
        ans = i;
    }
    
    cout << ans<< endl;
    for (long long i =ans; i >=1; i--){
        cout << index [i]<< " ";
        // cout << dp[i]<< endl;
    }
    return 0;
}