#include <bits/stdc++.h>
using namespace std;
int main(){
    double c;
    cin >> c;
    double mini =1, maxi = c;
    double ans = maxi;
    while (mini <= maxi){
        double mid = (maxi+mini)/2;
        double cur = mid*mid + sqrt (mid);
        if (cur==c){
            ans = mid;
            break;
        }
        else if (cur > c){
            maxi = mid-1;
        }
        else{
            mini = mid+1;
        }
    }
    cout << ans;
}