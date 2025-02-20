#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <tuple<long long, long long>> customers;
    for (long long i =0; i < n; i++){
        long long a, b;
        cin >> a>> b;
        customers.push_back(make_tuple (a,1));
        customers.push_back(make_tuple (b,-1));
    }
    sort (customers.begin(), customers.end());
    long long maxim =0;
    long long sum =0;
    for (long long i =0; i < customers.size(); i++){
        sum += get <1> (customers[i]);
        maxim = max (sum, maxim);
    }
    cout << maxim;
    return 0;
}

