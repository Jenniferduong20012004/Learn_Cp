#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    for (long long i =0; i < t; i++){
        long long n;
        cin >> n;
        vector <long long> myScore, ilyaScore;
        long long my=0, ilya =0;
        for (long long ii =0; ii < n; ii++){
            long long a;
            cin >> a;
            myScore.push_back (a);
        }
        for (long long ii =0; ii < n; ii++){
            long long a;
            cin >> a;
            ilyaScore.push_back (a);
        }
        sort (myScore.begin(), myScore.end());
        sort (ilyaScore.begin(), ilyaScore.end());
        for (long long j = n/4; j < n; j++){
            my += myScore[j];
            ilya += ilyaScore[j]; 
        }
        long long numAdd =0;
        long long ilyaPtr = n/4, myPtr = n/4;
        long long count =n%4;
        while (my < ilya){
            numAdd++;
            my+=100;
            count++;
            if (count ==4) {  
                my -= myScore[myPtr];
                myPtr++;
                count =0;                    
            } 
            else{
                if (ilyaPtr > 0) {  
                    ilyaPtr--;
                    ilya += ilyaScore[ilyaPtr];
                }
            }   

        }
        // cout << my << " "<< ilya<< endl;
        cout << numAdd<< endl;
    }
}