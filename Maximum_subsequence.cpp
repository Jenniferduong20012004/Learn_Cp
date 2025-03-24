#include<bits/stdc++.h>
using namespace std;
void tryX (long long i, long long currentMod, long long a, long long b, vector<long long> &left,vector<long long> &v){
    if (i> a){
        left.push_back (currentMod);
        return;
    }
    else{
        long long cur = (currentMod + v[i]%b)%b;
        tryX (i+1, cur, a,b,left, v);
        tryX(i+1, currentMod, a, b, left, v);
    }
}
int main(){
    long long a, b;
    cin >> a>> b;
    vector <long long> left, right;
    vector<long long> v;
    v.push_back (0);
    for (long long i =0; i < a; i++){
        long long num;
        cin >> num;
        v.push_back(num); 
    }
    tryX (1, 0, a/2,b,left, v);
    tryX (a/2+1, 0, a,b,right, v);
    sort (right.begin(), right.end());
    long long current =0;
    for (long long sum: left ){
        long long cur = upper_bound (right.begin(), right.end(), b- sum-1)- right.begin();
        cur --;
        if (cur >=0){
            current = max (current,(right[cur]+ sum)%b);
        }
        cur  = upper_bound (right.begin(), right.end(), b-1)-right.begin();
        cur--;
        if (cur >=0){
            current = max (current,(right[cur]+ sum)%b);
        }
        if (current == b-1){
            break;
        }
    }
    cout <<current;

}