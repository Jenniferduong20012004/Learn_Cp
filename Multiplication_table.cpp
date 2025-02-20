#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a;
    cin >> a;
    long long maxi = a*a;
    long long mini = 1;
    while (mini < maxi){
        long long mid = (maxi+mini)/2;
        long long count =0;
        for (long long i =1; i <=a; i++){
            count+= min (a,mid/i );
        }
        if (count >= (a*a+1)/2){
            maxi = mid;
        }
        else{
            mini = mid+1;
        }
    }
    cout << maxi;
}