#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin >> n>> k;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a;
        cin >> a;
        v.push_back (a);
    }
    for (long long i =0; i < k; i++){
        long long queri;
        cin >> queri;
        long long leftPointer =0, rightPointer = n-1;
        bool check = true;
        while (leftPointer <= rightPointer){
            long long mid = leftPointer+(rightPointer- leftPointer)/2;
            // 0 + 10/2 -> 5
            if (v[mid]== queri){
                check = false;
                cout << "YES"<< endl;
                break;
            }
            else if (v[mid]> queri){
                rightPointer = mid-1;
            }
            else{
                leftPointer= mid+1;
            }
        }
        if (check){
            cout << "NO"<< endl;
        }
    }
}