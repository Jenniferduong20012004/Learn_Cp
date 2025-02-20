#include <bits/stdc++.h>
using namespace std;
const long long MOD = 25071987;

long long luckyLuck (long long num, vector <long long> &ans, vector <long long> &broken){
    if (num ==1){
        return 1;
    }
    else if (num ==2){
        if (broken[num]==1){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if (ans[num]!=-1){
            return ans[num];
        }
        if (broken[num]==1){
            return 0;
        }
        return ans[num]= (luckyLuck(num-1, ans, broken)+ luckyLuck (num-2, ans, broken))%MOD;
    }
}
int main(){
    // freopen("dpgame.inp", "r", stdin);
    // freopen("dpgame.out", "w", stdout);
    long long n,k;
    cin >> n>>k;
    vector <long long> broken (n+1, -1);
    for (long long i =0; i < k; i++){
        long long a;
        cin >> a;
        broken[a]=1;
    }
    vector <long long> ans(n+1, -1);
    
    cout << luckyLuck (n, ans, broken);
    return 0;
}
    