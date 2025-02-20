#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000;

vector <long long> tinhtoan (long long cur, long long n, vector <long long> &deBai, vector <vector<long long>> &chaiBo){
    if (cur == n){
        vector <long long> a = {0,0};
        return a;
    }
    else if (cur == n-1){
        vector <long long> a = {deBai[n],1};
        return a;
    }
    else if (cur == n-2){
        vector <long long> a = {deBai[n]+ deBai[n-1],2};
        return a;
    }
    else{
        if (chaiBo[cur][0] != -1){
            return chaiBo[cur];
        }
        vector <long long> missTheNext = tinhtoan(cur+2, n, deBai, chaiBo);
        missTheNext[0]+=deBai[cur+1];
        missTheNext[1]++;
        vector <long long> missTheNextNext = tinhtoan (cur+3, n, deBai, chaiBo);
        missTheNextNext[0] +=(deBai[cur+1]+ deBai[cur+2]);
        missTheNextNext[1]+=2;
        vector <long long> missTheFirstNext = tinhtoan (cur+1, n, deBai, chaiBo);        
        if (missTheNext[0] > missTheNextNext[0]&& missTheNext[0]> missTheFirstNext[0]){
            return chaiBo[cur]= missTheNext;
        }
        else if (missTheNext[0] < missTheNextNext[0]&& missTheFirstNext[0] <missTheNextNext[0] ){
            return chaiBo[cur]= missTheNextNext;
        }
        else if (missTheFirstNext[0]> missTheNext[0]&& missTheFirstNext[0]>missTheNextNext[0]){
            return chaiBo[cur]= missTheFirstNext;
        }
        else{
            if (missTheNext[1] <= missTheNextNext[1] && missTheNext[1] <= missTheFirstNext[1]){
                return chaiBo[cur]= missTheNext;
            }
            else if (missTheNext[1] >= missTheNextNext[1] && missTheNextNext[1] <= missTheFirstNext[1]){
                return chaiBo[cur]= missTheNextNext;
            }
            else{
                return chaiBo[cur]= missTheFirstNext;
            }
        }
    }
}


// 0 45 56 91 35 81
//   45
//      56
int main(){
    // freopen("dpbottle.inp", "r", stdin);
    // freopen("dpbottle.out", "w", stdout);
    long long t;
    cin >> t;
    vector <long long> deBai;
    vector <vector<long long>> chaiBo (t+1,vector <long long> (2, -1));
    deBai.push_back (0);

    for (long long i =0; i < t; i++){
        long long a;
        cin >> a;
        deBai.push_back (a);
    }
    // 55 19 41 16 17
    // 55 19
    // 55 41
    vector <long long > res = tinhtoan (0, t, deBai, chaiBo);
    cout << res[1]<< " "<< res[0];

    return 0;
}
