#include <bits/stdc++.h>
using namespace std;
int main (){
    long long a, b;
    long long number = 1;
    while (cin >> a >> b){
        if (a ==0&& b ==0){
            break;
        }
        vector <vector <long long>> d(100+1, vector <long long> (100+1, LLONG_MAX));
        d[a][b] =1;
        long long c, e;
        while (cin >> c >> e){
            if (c==0 &&e ==0){
                break;
            }
            d[c][e]=1;
        }
        for (long long k =1; k < 101; k++){
            for (long long i =1; i < 101; i++){
                for (long long j =1; j < 101; j++){
                    if (d[i][k]< LLONG_MAX && d[k][j]< LLONG_MAX){
                        d[i][j]= min (d[i][j], d[i][k]+ d[k][j]);
                    }
                }
            }
        }
        long long numPair = 0;
        long long totalPair =0;
        for (long long i = 1; i < 101; i++){
            for (long long j = 1; j < 101; j++){
                if (i !=j){
                    if (d[i][j] != LLONG_MAX){
                        numPair++;
                        totalPair += d[i][j];
                    }
                }
            }

        }
        double ans = totalPair*1.0/ numPair;
        cout << "Case "<< number<<": average length between pages = " <<fixed<<setprecision(3) << ans<< " clicks" << endl;
        number++;

    }
}