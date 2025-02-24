#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n;
    cin >> n;
    map <char, long long> m;
    long long dif =0;
    vector <char> deBai;
    for (long long i =0; i < n; i++){
        char a;
        cin >> a;
        deBai.push_back (a);
        if (m[a]==0){
            dif ++;
            m[a]++;
        }
    }
    long long right = n -1, left = n-1;
    map <char, long long> save;
    long long diff =0;
    long long curSum =0;
    long long minSum =LLONG_MAX;
    while (right >= 0 && left >= right){
        char a = deBai[right];
        if (save[a]==0){
            diff++;
        }
        save[a]++;
        if (diff == dif){            
            curSum = left-right +1;
            while (diff == dif){
                save [deBai[left]]--;
                if (save [deBai[left]]==0){
                    diff--;
                }
                if (diff==dif){
                    curSum--;
                }
                left--;
            }
            minSum = min (minSum, curSum);
        }
        right --;
    }
    if (n==1){
        minSum =1;
    }
    cout << minSum;
}