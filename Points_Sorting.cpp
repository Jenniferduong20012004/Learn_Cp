#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<tuple<long, long, long>> points(n);
    for (long long i =0; i < n; i++){
        long long x, y, z;
        cin >> x>>y>>z;
        points[i]= make_tuple (x,y,z);
    }
    sort (points.begin(), points.end(), [](const auto & a, const auto& b){
        if (get<0> (a) != get<0> (b)){
            return get<0> (a) < get <0>(b);
        }
        else if(get <1>(a) != get <1>(b)){
            return get<1> (a) < get <1>(b);
        }
        else{
            return get<2> (a) < get <2>(b);
        }
    });
    for (long long i =0; i< n; i++){
        cout << get<0>(points[i])<<" "<< get<1>(points[i])<<" "<< get<2>(points[i])<< endl;
    }
}

