#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long, long long>> v;
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        v.push_back (make_tuple (a, b, i));
    }
    sort (v.begin(), v.end(),[](const auto &a, const auto &b){
        if (get <0> (a) != get <0> (b)){
            return get <0> (a) < get <0> (b);
        }
        else{
            return get <1> (a) > get <1> (b);
        }
    });
    vector <long long> firstRowAns (n, 0);
    vector <long long> secondRowAns (n, 0);
    long long minCur = get <1> (v[n-1]);
    for (long long i = n-2; i >=0; i--){
        if (get <1> (v[i]) >= minCur){
            firstRowAns[get<2>(v[i])]=1;
        }
        else{
            minCur = min (minCur,get <1> (v[i]) );
        }
    }
    long long maxCur = get <1>(v[0]); 
    for (long long i = 1; i < n; i++){
        if (get <1> (v[i]) <= maxCur){
            secondRowAns[get<2>(v[i])]=1;
        }
        else{
            maxCur = max (maxCur, get <1> (v[i]));
        }
    }
    for (long long i = 0; i < n; i++){
        cout << firstRowAns[i]<< " ";
    }
    cout << endl;
    for (long long i = 0; i < n; i++){
        cout << secondRowAns[i]<< " ";
    }
    return 0;
}


