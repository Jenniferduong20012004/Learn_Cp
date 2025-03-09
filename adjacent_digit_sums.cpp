#include <bits/stdc++.h>
using namespace std;
int main (){
    long long testcase;
    cin >> testcase;
    for (long long t =0; t < testcase; t++){
        long long a,b;
        cin >> a>> b;
        long long prev = 1;
        bool check = false;
        for (long long i =2; i <=10000;i++){
            long long temp = i;
            long long sumi =0;
            while (temp >0){
                sumi += temp % 10;
                temp -= temp  %10;
                temp /=10;
            }
            if (prev == a && sumi == b){
                check = true;
                break;
            }
            prev = sumi;
        }  
        if (check){
            cout << "Yes"<< endl;
        }   
        else{
            cout << "No"<< endl;
        }
    }
}