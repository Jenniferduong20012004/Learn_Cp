#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector <long long> first, second;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        first.push_back (a);
    }
    for (long long i =0; i < m; i++){
        long long a;
        cin >> a;
        second.push_back (a);
    }
    long long firstPointer =0, secondPointer =0;
    while (firstPointer != n && secondPointer != m){
        if (first[firstPointer]< second[secondPointer]){
            cout << first[firstPointer] << " ";
            firstPointer ++;
        }
        else if (first[firstPointer]> second[secondPointer]){
            cout << second[secondPointer] << " ";
            secondPointer ++;
        }
        else{
            cout << second[secondPointer] << " ";
            secondPointer ++;
        }
    }
    while (firstPointer < n){
        cout << first[firstPointer] << " ";
        firstPointer ++;
    }
    while (secondPointer < m){
        cout << second[secondPointer] << " ";
        secondPointer ++;
    }
    return 0;
}

