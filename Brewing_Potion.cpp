#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, x;
    cin >> n>> x;
    vector <long long > children;
    for (long long i =0; i < n; i++){
        long long a;
        cin>> a;
        children.push_back(a);
    }
    sort (children.begin(), children.end());
    long long leftPointer =0, rightPointer = n-1;
    long long res =0;
    while (leftPointer <= rightPointer){
        if (leftPointer== rightPointer){
            res+=1;
            break;
        }
        if (children[leftPointer]+ children[rightPointer]>x){
            res++;
            rightPointer--;
        }
        else{
            res++;
            rightPointer--;
            leftPointer++;
        }
    }
    cout << res;
    return 0;
}

