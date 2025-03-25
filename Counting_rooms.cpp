#include<bits/stdc++.h>
using namespace std;
void bfs (long long i, long long j, vector <vector<bool>> &visit, vector <string> &v, long long n,long long m){
    vector <long long> leftRightMove = {-1,1,0,0};
    vector <long long> upDownMove = {0,0,-1,1};
    visit [i][j] = true;
    queue <pair<int, int> > q;
    q.push ({i, j});
    while (!q.empty()){
        long long x = q.front().first;
        long long y = q.front().second;
        q.pop();
        for (long long d = 0; d < 4; d++){
            long long tempX = x + leftRightMove [d];
            long long tempY = y + upDownMove [d];   
            if (tempX< n && tempY < m && tempX>=0 && tempY >=0){
                if (v[tempX][tempY] == '.' && visit[tempX][tempY]== false){
                    visit[tempX][tempY]= true;
                    q.push ({tempX, tempY});
                }
            }
            
        }
    }

}
int main (){
    long long n, m;
    cin >> n >> m;
    vector <string> v;
    long long count =0;
    for (long long i =0; i < n; i++){
        string s ;
        cin >> s;
        v.push_back (s);
    }
    vector <vector<bool>> visit (n, vector<bool> (m, false));
    for (long long i =0; i < n; i++){
        for (long long j =0; j < m; j++){
            if (v[i][j]== '.'&& visit[i][j]== false){
                count++;
                bfs (i, j, visit, v, n,m);
            }
        }
    }
    cout << count << endl;
}