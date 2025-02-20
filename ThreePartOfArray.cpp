#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector <long long> v;
    for (long long i =0; i < n; i++){
        long long a ;
        cin >> a;
        v.push_back (a);
    }
    long long leftPointer =0, rightPointer = n-1, leftSum =v[0], rightSum=v[n-1];
    long long curMax =0;
    while (leftPointer < rightPointer){
        if (leftSum == rightSum){
            curMax = max (curMax, leftSum);
            leftPointer++;
            rightPointer--;
            if (leftPointer < rightPointer){
                leftSum+=v[leftPointer];
                rightSum += v[rightPointer];
            }
        }
        else if (leftSum < rightSum){
            leftPointer++;
            if (leftPointer < rightPointer){
                leftSum+=v[leftPointer];
            }
        }
        else{
            rightPointer --;
            if (leftPointer < rightPointer){
                rightSum += v[rightPointer];
            }
        }
    }
    cout << curMax;
}