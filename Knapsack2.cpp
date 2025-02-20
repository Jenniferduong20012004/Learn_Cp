#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, maxi;
    cin >> n>> maxi;
    vector <vector<long long>>v;
    vector <long long> weight (max)
    for (long long i =0; i <n; i++){
        long long a,b;
        cin >> a>> b;
        vector <long long> vv;
        vv.push_back (a);
        vv.push_back (b);
        v.push_back (vv);
    }
    cout <<tinhtoan (0,maxi,0,v,dp);
}