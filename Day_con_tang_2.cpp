#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("dpliq2.inp", "r", stdin);
    // freopen("dpliq2.out", "w", stdout);
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >>a;
        v.push_back (a);
    }
    vector <long long> dp (n, 1);
    vector <vector <long long>> day;
    for (long long i =0; i < n; i++){
        vector <long long> first;
        first.push_back (i+1);
        day.push_back (first);
    }
    long long maxi =0, curMaxIndex =0;
    for (long long i = 1; i < n; i++){
        for (long long j =0; j < i; j++){
            if (v[i]> v[j]){
                if (dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    vector <long long> temp = day[j];
                    temp.push_back (i+1);
                    day[i]=temp;
                }
            }
        }
    }
    for (long long i =0; i < n; i++){
        if (dp[i]> maxi){
            curMaxIndex = i;
            maxi = dp[i];
        }
    }
    cout << maxi<< endl;
    for (long long i =0; i < day[curMaxIndex].size(); i++){
        cout << day[curMaxIndex][i]<<" ";
    }
    
    return 0;
}