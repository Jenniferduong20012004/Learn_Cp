#include <bits/stdc++.h>
using namespace std;
bool check (long long mid, long long n, vector <long long> &nums, long long k){
    long long op =0;
    for (long long i = n/2; i <n; i++){
        if ((mid- nums[i])>=0){
            op += (mid - nums[i]);
        }
        if (op > k){
            return false;
        }
    }
    if (op <= k){
        return true;
    }
    return false;
}
int main(){
    long long n, k;
    cin >> n>> k;
    vector <long long> v;
    long long maxi = LLONG_MIN;
    for (long long i =0; i <n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
        maxi = max (maxi, a);
    }
    // sort (v.begin(), v.end());
    maxi +=k;
    long long mini = 0;
    long long ans= maxi;
    while (mini <= maxi){
        long long mid = mini + (maxi - mini)/2;
        if (check (mid, n, v, k)){
            mini = mid;
            ans = mini;
        }
        else{
            maxi = mid-1;
        }
    }
    cout << ans;


}