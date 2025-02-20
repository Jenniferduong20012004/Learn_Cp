#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin >> n>> k;
    vector <long long> exercise;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        exercise.push_back (a);
    }
    vector <long long> dp (n, 1);
    map <long long, long long> m;
    m[exercise[n-1]]++;
    long long r = n-1;
    for (long long i = n-2; i >=0; i--){
        m[exercise[i]]++;
        // cout << m.size()<< " ";
        if (m.size() <=k){
            dp[i]+= (r-i);
        }
        else{
            // cout << r<< " "<<i << endl;
            while (m.size()>k){
                m[exercise[r]]--;
                if (m[exercise[r]]==0){
                    m.erase(exercise[r]);
                    r--;
                    break;
                }
                r--;
            }
            dp[i]+= (r-i);
        }
        dp[i]+= dp[i+1];
    }
    // cout << endl;
    // for (long long i =0; i <n; i++){
    //     cout << dp[i]<< " ";
    // }
    cout << dp[0];
    return 0;
}
// 1 2 3 1 1 
// 10 8 6 3 1
