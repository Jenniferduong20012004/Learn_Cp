#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <tuple <long long, long long>> tasks;
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        tasks.push_back (make_tuple (a, b));
    }
    sort (tasks.begin(), tasks.end());
    vector <long long> dp (n, 0);
    long long sumOfTimeTillCurrent =0;
    for (long long i =0; i < n; i++){
        if (i==0){
            dp[i]= get <1> (tasks[i])- get <0> (tasks[i]);
        }
        else{
            dp[i]= max (get<1> (tasks[i]) - sumOfTimeTillCurrent - get<0> (tasks[i]) + dp[i-1], get<1> (tasks[i])- get<0> (tasks[i])+ dp[i-1]- (i+1)* get<0> (tasks[i]));
        }
        sumOfTimeTillCurrent += get <0> (tasks[i]);
    }
    cout << dp[n-1];
    return 0;
}