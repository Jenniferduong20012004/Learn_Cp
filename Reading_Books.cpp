#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
   cin >> n;
   vector <long long> books;
   long long sumi =0;
   for (long long i =0; i < n; i++){
    long long a ;
    cin >> a;
    sumi +=a;
    books.push_back (a);
   }
   sort (books.begin(), books.end());
   long long maxi = books[n-1];
   sumi -=maxi;
   if (maxi >= sumi){
        cout << maxi *2;
   }
   else{
    cout<< maxi+ sumi;
   }

   
    return 0;
}