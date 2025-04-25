#include <bits/stdc++.h>
using namespace std;
long long findOne (long long a,vector <long long> &find, vector <long long> &maxi, vector <long long> &mini, vector <long long> &tong){
    if (find[a]==a){
        return a;
    }
    else{
        find[a]= findOne (find[a], find, maxi, mini, tong);
        return find[a];
    }
}
void unionSet (long long a, long long b, vector <long long> &find , vector <long long> &maxi, vector <long long> &mini, vector <long long> &tong){
    long long parA = findOne(a, find, maxi, mini, tong);
    long long parB = findOne(b, find, maxi, mini, tong);
    if (parA!= parB){
        find[parB]= parA;
        maxi[parA]= max (maxi[parA], maxi[parB]);
        mini[parA]= min (mini[parA], mini[parB]);
        tong[parA] += tong[parB];
    }
    return;
}
int main (){
    long long a, b;
    cin >> a>> b;
    vector <long long> find (a+1, 0);
    vector <long long> maxi (a+1, 0);
    vector <long long> mini (a+1, LLONG_MAX);
    vector <long long> tong (a+1, 1);
    for (long long i =1; i <= a; i++){
        find[i]= i;
        maxi [i]=i;
        mini [i]= i;
    }
    for (long long i =1; i <=b; i++){
        string s;
        cin >> s;
        if (s== "union"){
            long long c, d;
            cin >> c >> d;
            unionSet (c,d,find, maxi, mini, tong);
        }
        else{
            long long c;
            cin >> c;
            long long par = findOne(c, find, maxi, mini, tong);
            
            cout << mini[par]<< " "<< maxi[par]<< " "<< tong[par]<< endl;
        }
    }


}