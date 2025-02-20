#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> movies(n);
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        movies[i]= make_tuple (b, a);
    }
    sort (movies.begin(), movies.end());
    long long res =0;
    long long prevEnd = LLONG_MIN;
    for (long long i =0; i < n; i++){
        if (get<1>(movies[i]) >= prevEnd){
            res++;
            prevEnd = get<0>(movies[i]);
        }
    }
    cout << res;
    return 0;
}

