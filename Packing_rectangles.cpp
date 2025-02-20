#include <bits/stdc++.h>
using namespace std;
int main (){
    long long w,h,n;
    cin >> w>>h>>n;
    long long maxi = 1;
    while ((maxi/w)*(maxi/h)<n){
        maxi*=2;
    }
    long long mini = 0;
    long long ans =0;
    while (mini <= maxi){
        long long mid = (maxi+mini)/2;
        long long sumOfRec =(mid/w)*(mid/h);
        
        if (sumOfRec>=n){
            ans = mid;
            maxi = mid-1;
        }
        else{
            mini = mid +1;
        }
    }
    cout << ans;
    
}