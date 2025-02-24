#include <bits/stdc++.h>
using namespace std;
int main (){
    long long tcase;
    cin >> tcase;
    for (long long i =0; i < tcase; i++){
        long long n;
        cin >> n;
        vector <long long > a;
        for (long long j =0; j < n; j++){
            long long r;
            cin >> r;
            a.push_back (r);
        }
        long long maxi =0;
        long long left =0, right = n-1;
        long long alice=0, bob =0;
        while (left<right){
            if (alice == bob){
                alice += a[left];
                bob += a[right];
                if (alice == bob){
                    maxi = max (maxi,left + n-right+1);
                }
                left ++;
                right--;
            }
            else if (alice > bob){
                while (alice >bob && left < right){
                    bob += a[right];
                    if (alice == bob){
                        maxi = max(maxi,left + n-right);
                    }
                    right--;
                }
            }
            else {
                while (alice <bob && left < right){
                    alice += a[left];
                    if (alice == bob){
                        maxi = max (maxi,left + n-right);
                    }
                    left ++;
                }
            }
        }
        if (alice != bob&& left == right){
            if (alice + a[left]== bob|| bob+a[left]== alice){
                maxi = n;
            }
        }
        cout << maxi<< endl;
    }
}

