#include <bits/stdc++.h>
using namespace std;
long long tinhtoan (long long curId, long long prevAc, vector <vector<long long>>&v, vector <vector<long long>>&dp){
    if (curId == v.size()){
        return 0;
    }
    else {
        if (dp[curId][prevAc]!= -1){
            return dp[curId][prevAc];
        }
        if (prevAc== 0){
            dp[curId][prevAc] = max (v[curId][1]+ tinhtoan (curId+1, 1, v, dp),v[curId][2]+ tinhtoan (curId+1, 2, v, dp) );
        }
        else if (prevAc ==1){
            dp[curId][prevAc] = max (v[curId][0]+ tinhtoan (curId+1, 0, v, dp),v[curId][2]+ tinhtoan (curId+1, 2, v, dp) );
        }
        else{
            dp[curId][prevAc] = max (v[curId][0]+ tinhtoan (curId+1, 0, v, dp),v[curId][1]+ tinhtoan (curId+1, 1, v, dp));
        }
        return dp[curId][prevAc];
    }
}
int main(){
    long long n;
    cin >> n;
    vector <vector<long long>>v;
    vector<vector<long long>>dp (n, vector <long long> (3, -1));
    for (long long i =0; i <n; i++){
        long long a,b,c;
        cin >> a>> b>> c;
        vector <long long> vv;
        vv.push_back (a);
        vv.push_back (b);
        vv.push_back (c);
        v.push_back (vv);
    }
    cout << max (v[0][0]+ tinhtoan (1, 0, v, dp), max(v[0][1]+ tinhtoan (1, 1, v, dp), v[0][2]+ tinhtoan (1, 2, v, dp)));
}