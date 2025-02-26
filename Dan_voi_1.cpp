#include <bits/stdc++.h>
using namespace std;
int main (){
    // freopen("dpvoi.inp", "r", stdin);
    // freopen("dpvoi.out", "w", stdout);
    long long a, b;
    vector <tuple<long long, long long, long long>> voi;
    vector <vector<long long>> dp;
    long long ii =1;
    while (cin >> a >> b && (a != 0 || b != 0)){
        voi.push_back (make_tuple(a, b, ii));
        ii++;
    }
    sort (voi.begin(), voi.end());
    for (long long i =0; i <  voi.size(); i++){
        vector <long long> temp;
        temp.push_back (get<2> (voi[i]));
        dp.push_back (temp);
    }
    for (long long i =1; i < voi.size(); i++){
        for (long long j =0; j < i; j++){
            if (get <1> (voi[i]) < get <1> (voi[j])){
                vector <long long> temp = dp[j];
                temp.push_back (get<2> (voi[i]));
                if (dp[i].size()< temp.size()){
                    dp[i]= temp;
                }
            }
        }
    }
    long long curIndexMax =0, maxi =0;
    for (long long i =0; i <  voi.size(); i++){
        if (maxi < dp[i].size()){
            curIndexMax = i;
            maxi = dp[i].size();
        }
    }
    cout << maxi<< endl;
    for (long long i =0; i < dp[curIndexMax].size(); i++){
        cout << dp[curIndexMax][i]<< " ";
    }
}