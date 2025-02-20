#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long fibonanci (long long num, vector <long long> &table){
    if (num ==1){
        return 1;
    }
    else if (num ==2){
        return 1;
    }
    else{
        if (table[num]!= -1){
            return table[num];
        }
        table[num]= (fibonanci (num-1, table)+ fibonanci (num-2, table))%MOD;
        return table[num];
    }
}
int main(){
    // freopen("dpfibo1.inp", "r", stdin);
    // freopen("dpfibo1.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> table(n+1, -1);
    cout << fibonanci (n, table);
    return 0;
}
    