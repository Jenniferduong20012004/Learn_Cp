#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a, b;
    while (cin >> a>> b){
        if (a ==0 && b ==0){
            break;
        }
        vector <pair<long long>> v (a+1);
        for (long long i =1; i <= a; i++){
            long long c, d;
            cin >> c>> d;
            v[i]={c,d};
        }
        vector <vector <long long>> curRoad (a+1, vector <long long> (a+1, LLONG_MAX));
        for (long long i =1; i <=b; i++){
            long long c, d;
            cin >> c>> d;
            curRoad [c][d]= sqrt (v[c].first)
        }
    }
}