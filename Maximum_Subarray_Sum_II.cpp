#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, a, b;
    cin >> n>> a>> b;
    vector <long long> prefixSum (n+1, 0);
    for (long long i =1; i <= n; i++){
        long long a;
        cin >> a;
        prefixSum[i]= prefixSum[i-1]+a;
    }
    deque<long long> dq;
    long long res = LLONG_MIN;
    for (int i = 1; i < b; i++){
        while (!dq.empty() && prefixSum[dq.front()]<= prefixSum[i]){
            dq.pop_front();
        }
        dq.push_front (i);
    }
    for (long long i =0; i <= (n-a);i++){
        while (i +b <= n && !dq.empty() && prefixSum [dq.front()] <= prefixSum[i+b]){
            dq.pop_front();
        }
        if (i+b <= n){
            dq.push_front(i+b);
        }
        while (!dq.empty()&& dq.back() < (a+i)){
            dq.pop_back();
        }
        res = max (res, prefixSum[dq.back()]- prefixSum[i]);
    }
    cout << res;
    return 0;
}

