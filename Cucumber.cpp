#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> v;
    for (long long i =0; i < n; i++){
        long long a,b;
        cin >> a>>b;
        v.push_back (make_tuple(a,b));
    }
    sort (v.begin(), v.end());
    long long curSum =1;
    long long curMinEnd = get <1> (v[0]);
    for (long long i =1; i <n ; i++){
        long long dayEnd = get <1> (v[i]);
        long long dayStart = get <0> (v[i]);
        if (dayStart > curMinEnd){
            curSum++;
            curMinEnd = dayEnd;
        }
        else if (dayEnd < curMinEnd){
            curMinEnd = dayEnd;
        }
    }
    cout << curSum;
    return 0;
}

