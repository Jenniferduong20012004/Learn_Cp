#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    long long maxi =LLONG_MAX;
    long long left =0, right =0;
    long long curSum =0;
    while (right <n){
        curSum+=v[right];
        if (curSum>= m){
            while (curSum>=m){
                maxi = min (maxi, right-left+1);
                curSum-=v[left];
                left++;
            }
        }
        right++;
    }
    if (maxi == LLONG_MAX){
        maxi = -1;
    }
    cout << maxi;
    return 0;
}

