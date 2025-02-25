#include <bits/stdc++.h>
using namespace std;
int main (){
    long long timefree, numBook;
    cin >> numBook>> timefree ;
    vector <long long> books;
    for (long long i =0; i < numBook; i++){
        long long a;
        cin >> a;
        books.push_back (a);
    }
    long long left =0, right =0;
    long long ans =0, curSum =0;
    while (right < numBook){
        curSum += books[right];
        if (curSum <= timefree){
            ans = max (ans, right-left+1);
        }
        else{
            while (curSum> timefree){
                curSum-= books[left];
                left++;
                if (curSum <= timefree){
                    ans = max (ans, right-left+1);
                }
            }
        }
        right ++;
    }
    cout << ans;

}