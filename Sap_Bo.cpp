#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000;

long long SapBo (long long n, long long k, long long prevGioiTinh, vector <vector <long long>> &cachSapXep){
    if (n ==0){
        return 1;
    }
    else{
        if (cachSapXep[n][prevGioiTinh]!=-1){
            return cachSapXep[n][prevGioiTinh];
        }
        if (prevGioiTinh==0){ // cai
            return cachSapXep[n][prevGioiTinh] =(SapBo (n-1,k, 0, cachSapXep)+ SapBo (n-1, k, 1, cachSapXep))%MOD;
        }
        else{ // duc
            if (n <= k){
                return cachSapXep[n][prevGioiTinh] = SapBo (0, k,0,cachSapXep)%MOD;
            }
            else{
                return cachSapXep[n][prevGioiTinh] = SapBo (n-k, k,0,cachSapXep)%MOD;
            }
        }
        
    }
}
//5
//M-F
//MFF - FF - FM
//MFFM - MFFF - FF
int main(){
    // freopen("dpsabo.inp", "r", stdin);
    // freopen("dpsabo.out", "w", stdout);
    long long n,k;
    cin >> n>>k;
    vector <vector <long long>> cachSapXep (n+1, vector<long long> (2, -1));
    long long ans =(SapBo(n-1,k,0, cachSapXep)+ SapBo (n-1,k,1,cachSapXep))%MOD;
    // for (long long i =0; i < n+1; i++){
    //     for (long long j =0; j <2; j++){
    //         cout << cachSapXep[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    cout <<ans;
    return 0;
}
    