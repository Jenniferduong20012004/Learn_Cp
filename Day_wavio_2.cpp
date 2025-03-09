#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("dpwavio2.inp", "r", stdin);
    // freopen("dpwavio2.out", "w", stdout);
    long long n;
    vector <long long> v;
    cin >> n;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    // lis
    vector <long long> dp (n+1, LLONG_MAX);
    vector <long long> lis_left(n, 0);
    vector <long long> dp_right (n+1, LLONG_MAX);
    vector <long long> lis_right(n, 0);
    dp_right[0]= LLONG_MIN;
    dp[0]= LLONG_MIN;
    for (long long i =0; i < n; i++){
        long long cur = v[i];
        long long des = upper_bound (dp.begin(), dp.end(), cur)- dp.begin();
        if (dp[des-1]< cur){
            dp[des]= cur;
            lis_left[i]= des;
        }
        else{
            lis_left[i]= des-1;
        }
    }
    for (long long i =n-1; i >=0; i--){
        long long cur = v[i];
        long long des = upper_bound (dp_right.begin(), dp_right.end(), cur)- dp_right.begin();
        if (dp_right[des-1]< cur){
            dp_right[des]= cur;
            lis_right[i]= des;
        }
        else{
            lis_right[i]= des-1;
        }
    }
    long long maxi =0;
    for (long long i =0;i < n; i++){
        // cout << lis_left [i]<< " "<< lis_right[i]<< endl;
        maxi = max(maxi,lis_right[i]+ lis_left[i]-1);
    }
    cout << maxi;
    // tinh wavio tu lis
}