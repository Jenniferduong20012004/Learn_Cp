#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n, m;
    cin >> n>> m;
    vector <long long > cities, net;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        cities.push_back (a);
    }
    for (long long i =0; i < m; i++){
        long long a;
        cin >> a;
        net.push_back (a);
    }
    long long flag =0;
    vector <long long > dp (n, -1);
    for (long long i =0; i < n; i++){
        if (i ==0){
            long long des = lower_bound (net.begin(), net.end(), cities[i])- net.begin();
            if (des ==0){
                dp[i]= abs (cities[i]-net[des]);
                flag = des;
            }
            else if (des == m){
                dp[i]= abs (cities[i]-net[des-1]);
                flag = des-1;
            }
            else{
                if (abs (cities[i]-net[des-1])> abs (cities[i]-net[des])){
                    flag = des;
                    dp[i]= abs (cities[i]-net[des]);
                }
                else{
                    flag = des-1;
                    dp[i]= abs (cities[i]-net[des-1]);
                }
            }
        }
        else{
            long long curCelDis = abs(cities[i] - net[flag]);
            long long nextflag = flag+1;
            while (nextflag < m){
                long long nextCelDis = abs(cities[i] - net[nextflag]);
                if (nextCelDis < curCelDis){
                    flag= nextflag;
                    curCelDis = nextCelDis;
                    nextflag++;
                }
                else{
                    break;
                }
            }
            dp[i]= max (dp[i-1], curCelDis);
        }
    }
    cout << dp[n-1];
}