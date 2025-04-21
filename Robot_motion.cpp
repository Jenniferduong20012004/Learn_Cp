#include <bits/stdc++.h>
using namespace std;
long long step =0;
bool bfs (vector <string> &v, long long x, long long y, long long a, long long b, vector <vector<long long>> &visit){
    if (y < 0 || y >= a || x < 0|| x >= b){
        cout << step<< " step(s) to exit"<< endl;
        return true;
    }
    if (visit[y][x] >= 0){
        cout <<  visit[y][x]<< " step(s) before a loop of "<<(step- visit[y][x])<< " step(s)"<<endl;
        return false;
    }
    else{   
        visit[y][x]= step;
        step ++; 
        long long cur =0;
        if (v[y][x]== 'W'){
            return bfs (v, x-1, y, a, b, visit);
        }
        else if (v[y][x]== 'E'){
            return bfs (v, x+1, y, a, b, visit);
        }
        else if (v[y][x]== 'N'){
            return bfs (v, x, y-1, a, b, visit);
        }
        else{
            return bfs (v, x, y+1, a, b, visit);
        }
}

}
int main (){
    long long a, b , c;
    while (true){
        cin >> a >> b >> c;
        if (a ==0 && b ==0 && c==0){
            break;
        } 
        vector <string> v;
        vector <vector<long long>> visit (a, vector<long long> (b, -1));
        for (long long i =0; i < a; i++){
            string s;
            cin >> s;
            v.push_back (s);
        }
        c--;
        long long res = bfs (v, c, 0, a, b, visit);
        step =0;

    }
}