#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
   cin >> n;
   vector <long long> songs;
   for (long long i =0; i < n; i++){
    long long a ;
    cin >> a;
    songs.push_back (a);
   }
    long long left =0;
    long long right =1;
    long long maxi =1;
    long long sum =1;
    map <long long, long long> m;
    m[songs[left]]++;
    while (right < n){
        // for (auto it= m.begin(); it != m.end(); it++){
        //     cout << it-> first<< " "<< it-> second<< endl;
        // }
        // cout << endl;
        if (m[songs[right]] ==0){
            sum ++;
            maxi = max (maxi, sum);
            m[songs[right]]++;
            right ++;
        }
        else{
            // cout << songs[left] << " "<< songs[right]<< endl;
            if (songs[left]==songs[right]){
                left++;
                maxi = max (maxi, sum);
                right ++;
            }
            else{
                while (songs[left] != songs[right]){
                    m[songs[left]]--;
                    sum --;
                    left++;
                }
                left++;
                maxi = max (maxi, sum);
                right++;

            }
        }
    }
    cout << maxi;
    return 0;
}
//55 552 4
//57 57 4