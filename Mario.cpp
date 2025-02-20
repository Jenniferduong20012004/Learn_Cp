#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000;
int main(){
    // freopen("dpmario.inp", "r", stdin);
    // freopen("dpmario.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> coc;
    vector <long long> luu (n+2, 0);
    coc.push_back (0);

    for (long long i =0;i < n; i++){
        long long a;
        cin >> a;
       
        coc.push_back (a);
    }
    coc.push_back (0);
    luu[0]=1;
    for (long long i =1; i < n+2; i++){
            if (coc[i]==0){
                luu[i]= (luu[i] %MOD +luu[i-1]%MOD) %MOD;
                if (i-2 >=0){
                    luu[i] = (luu[i]%MOD + luu [i-2]%MOD)%MOD;
                } 
                if (i-3 >=0 && coc[i-3]!=1){
                    luu [i] = (luu[i]%MOD+ luu [i-3]%MOD)%MOD;
                }
            }
            else if (coc[i]==1){
                luu[i]= (luu[i-1]%MOD);
            }
    }

    cout << luu [n+1];
    
}