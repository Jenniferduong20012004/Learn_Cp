#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
   cin >> n>> k;
   vector <tuple<long long, long long>> movies;
   for (long long i =0; i < n; i++){
    long long a, b;
    cin >> a>>b;
    movies.push_back (make_tuple (a, b));
   }
   sort (movies.begin(), movies.end(), [](const auto &a, const auto &b){
    if (get <0>(a)!= get <0> (b)){
        return get <0> (a)< get <0> (b);
    }
    else{
        return get <1> (a)< get <1> (b);
    }
   });
   map <long long, long long> check;
   for (long long i =0; i < k; i++){
    check[get<1>(movies[i])]++;
   }
   long long ans = k; 
   for (long long i =k; i <n; i++){
    long long curFilmStart = get<0>(movies[i]);
    long long curFilmEnd = get<1>(movies[i]);
    long long minFilmEndInMap = check.begin()-> first;
    long long maxFilmEndInMap = check.rbegin()->first;
    if (curFilmStart >= minFilmEndInMap){
        check[minFilmEndInMap]--;
        if (check[minFilmEndInMap]==0){
            check.erase (minFilmEndInMap);
        }
        check[get<1>(movies[i])]++;
        ans++;
    }
    else if (curFilmEnd <= maxFilmEndInMap){
        check[maxFilmEndInMap]--;
        if (check[maxFilmEndInMap]==0){
            check.erase (maxFilmEndInMap);
        }
        check [get<1>(movies[i])]++;
    }
   }
   cout << ans;
   
    return 0;
}