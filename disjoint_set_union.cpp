#include <bits/stdc++.h>
using namespace std;
long long findOne (long long a,vector <long long> &find ){
    if (find[a]==a){
        return a;
    }
    else{
        return find[a]= findOne (find[a], find);
    }
}
void unionSet (long long a, long long b, vector <long long> &find ){
    long long parA = findOne(a, find);
    long long parB = findOne(b, find);
    if (parA!= parB){
        find[parB]= parA;
    }
    return;
}
int main (){
    long long a, b;
    cin >> a>> b;
    vector <long long> find (a+1, 0);
    for (long long i =1; i <= a; i++){
        find[i]= i;
    }
    for (long long i =1; i <=b; i++){
        string s;
        long long c, d;
        cin >> s;
        cin >> c >> d;
        if (s== "union"){
            unionSet (c,d,find);
        }
        else{
            if (findOne(c, find)== findOne(d, find)){
                cout << "YES"<< endl;
            }
            else{
                cout << "NO"<< endl;
            }
        }
    }


}