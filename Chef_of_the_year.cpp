#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m;
    cin >> n>> m;
    map <string, string> chefWithCountry;
    map <string, long long> chef, countries;
    for (long long i =0; i < n; i++){
        string name, country;
        cin >> name>> country;
        chefWithCountry[name]= country;
        chef[name]++;
        countries[country]++;
    }
    for (long long i =0; i < m; i++){
        string name;
        cin >> name;
        chef[name]++;
        countries[chefWithCountry[name]]++;
    }
    long long maxOfNation = 0, maxOfChef =0;
    string ansNa= "zzzzzzzzzz", ansChef= "zzzzzzzzzz";
    for (auto iterator = chef.begin(); iterator != chef.end(); iterator++){
        if (iterator-> second > maxOfChef){
            ansChef= iterator -> first;
            maxOfChef = iterator -> second;
        }
    }
    for (auto iterator = countries.begin(); iterator != countries.end(); iterator++){
        if (iterator-> second >maxOfNation){
            ansNa= iterator -> first;
            maxOfNation = iterator -> second;
        }
    }
    cout << ansNa<< endl<< ansChef;

}