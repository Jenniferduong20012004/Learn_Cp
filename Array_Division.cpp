#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin >> n >> k;
    vector <long long> exercise;
    long long high =0;
    for (long long i =0; i < n; i++){
        long long a;
        cin >>a;
        high +=a;
        exercise.push_back (a);
    }
    long long low = *max_element (exercise.begin(), exercise.end());
    long long ans =0;
    while (low <= high){
        long long mid = (low+ high)/2;
        bool check = false;
        long long partition =1, runningSum =0;
        for (long long i =0; i< exercise.size(); i++){
            runningSum += exercise[i];
            if (runningSum > mid){
                runningSum = exercise[i];
                partition +=1;
            }
        }
        if (partition <=k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans;
    return 0;
}