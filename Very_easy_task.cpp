#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, x, y;
    cin >> n>> x>>y;
    long long mini =min (x,y), maxi = min (x,y)*n;
    long long ans = maxi;
    while (mini <= maxi){
        long long mid =(maxi+mini)/2;
        long long curSum = (mid-min(x,y))/x + (mid-min(x,y))/y+1;
        if (curSum >=n){
            ans = mid;
            maxi = mid -1;
        }
        else{
            mini = mid+1;
        }
    }
    cout << ans;
}