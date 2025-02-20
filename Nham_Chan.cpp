#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("dpbore.inp", "r", stdin);
    // freopen("dpbore.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long > deBai;
    vector <long long> dp (n, 0);
    map <long long , long long> m;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
    }
    for (long long i =n-1; i >=0; i--){
        if (i==n-1){
            m[deBai[i]]++;
            dp[i]= deBai[i];
        }else{

        }
    }
}