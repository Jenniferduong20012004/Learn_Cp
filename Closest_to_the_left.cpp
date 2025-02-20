#include <bits/stdc++.h>
using namespace std;
int main (){
    long long n, k;
    cin >> n>> k;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    for (long long i =0; i < k; i++){
        long long a;
        cin >> a;
        long long leftPointer =0, rightPointer = n-1;
        while (leftPointer <= rightPointer){
            long long mid = leftPointer + (rightPointer - leftPointer)/2;
            if (v[mid]> a){
                rightPointer = mid -1;
            }
            else{
                leftPointer = mid+1;
            }
        }
        cout << leftPointer<< endl;
    }
}
// 3 9 -> 5
// 3 5 -> 3
// 3 3 -> 3