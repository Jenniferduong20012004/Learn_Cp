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
    long long maxi =0;
    long long left =0, right =0;
    long long curSum =0;
    while (right <n){
        curSum+=v[right];
        if (curSum>= m){

            while (curSum>=m){

                maxi += (n-right);
                curSum-=v[left];
                left++;
            }
        }
        right++;
    }
    cout << maxi;
    return 0;
}

