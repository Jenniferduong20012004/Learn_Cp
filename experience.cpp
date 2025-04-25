#include <bits/stdc++.h>
using namespace std;
long long finding(long long a,vector <long long> &find  ){
    if (a== find[a]){
        return a;
    }
    else{
        return finding(find[a], find);;
    }
}
void unioning(long long a, long long b, vector <long long> &find,  vector <long long> &extra, vector <long long> &experience, vector <long long> &size){
    long long parA = finding (a, find);
    long long parB= finding (b, find);
    if (parA != parB){
        if (size[parA]< size[parB]){
            swap(parA, parB);
        }
        size[parA]+= size[parB];
        find[parB]= parA;
        extra[parB]= experience[parA];
    }
}
void adding (long long a, long long b, vector <long long> &find, vector <long long> &experience,  vector <long long> &extra){
    long long parA = finding(a, find);
    experience[parA]+=b;
}
long long getPoint (long long m,  vector <long long> &extra,  vector <long long> &experience,  vector <long long> &find){
    long long amt = experience[m];
    if (find[m]==m){
        return amt;
    }
    amt+= getPoint(find[m], extra, experience, find)- extra[m];
    return amt;
}
int main (){
    long long a, b;
    cin >> a >> b;
    vector <long long>experience (a+1, 0);
    vector <long long> find (a+1, 0);
    vector <long long> extra (a+1, 0);
    vector <long long> size (a+1, 1);
    for (long long i =1; i <=a; i++){
        find[i]= i;
    }
    for (long long i = 0; i < b; i++){
        string s;
        cin >> s;
        if (s== "add"){
            long long m, n;
            cin >> m>> n;
            adding (m,n, find, experience, extra);
        }
        else if (s == "join"){
            long long m, n;
            cin >> m>> n;
            unioning(m,n, find, extra, experience, size);
        }
        else{
            long long m;
            cin >> m;
            cout << getPoint(m, extra, experience, find)<< endl;
        }
    }
}

